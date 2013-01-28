#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <asm/ldt.h>

#define N_DESCS (6)
#define N_ITEMS (10)
#define PG_SIZE (1 << 12)

// TODO: do not know why we need this. 
extern int modify_ldt(int, void *, unsigned long);

int arr[N_ITEMS];

void read_ldts() {
	struct user_desc descs[N_DESCS];
	int n_bytesread;
	// Read LDTs. 
	n_bytesread = modify_ldt(0, descs, sizeof(struct user_desc) * N_DESCS);
	if (n_bytesread == -1) {
		perror("modify_ldt");
		return;
	}
	printf("# of bytes read = %d\n", n_bytesread);
}

void write_ldts() {
	struct user_desc desc;
	int edx;

	// Write LDTs.
	memset(&desc, 0, sizeof(desc));
	desc.seg_32bit = 1;
	desc.read_exec_only = 0;
	desc.limit_in_pages = 1;
	desc.seg_not_present = 0;
	desc.useable = 1;
	desc.entry_number = 0;
	desc.base_addr = (unsigned long)arr;
	desc.limit = (sizeof(arr) + PG_SIZE - 1) / PG_SIZE;
	desc.contents = MODIFY_LDT_CONTENTS_DATA;
	if (modify_ldt(1, &desc, sizeof(desc)) < 0) {
		perror("write: modify_ldt");
		return;
	}
	// Change %ds. 
	asm volatile("movw $7, %cx");
	asm volatile("movw %cx, %ds");
#if 1
	asm volatile("mov 4028, %edx");
#endif
	// Restore %ds. 
	asm volatile("movw $0x7b, %cx");
	asm volatile("movw %cx, %ds");

	// Dump edx.
	asm volatile("movl %%edx, %0"
			: "=rm"(edx));
	printf("edx = %08x\n", edx);
}

void dump_regs() {
	unsigned short ds, es, fs, gs, ss;
	asm("movw %%ds, %0;"
			"movw %%es, %1;"
			"movw %%fs, %2;"
			"movw %%gs, %3;"
			"movw %%ss, %4;"
			: "=rm"(ds), "=rm"(es), "=rm"(fs), "=rm"(gs), "=rm"(ss));
	printf("Registers: ds = %04x es = %04x fs = %04x gs = %04x ss = %04x\n",
			ds, es, fs, gs, ss);
}

void init() {
	int i;
	for (i = 0; i < N_ITEMS; ++i)
		arr[i] = i;
}

int main() {
	init();
	read_ldts();
	dump_regs();
	write_ldts();	
	return 0;
}

