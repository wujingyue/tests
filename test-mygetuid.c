#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	int i;
	for (i = 0; i < 1000000; i++) {
		uid_t ret;
		asm volatile("movl $199, %%eax; int $0x80; movl %%eax, %0;"
				: "=g"(ret));
		if (ret == -1)
			exit(1);
	}
	return 0;
}

