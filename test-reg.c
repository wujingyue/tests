#include <stdio.h>

int main() {
	int esp;
	asm volatile("mov %%esp, %0":
			"=g"(esp));
	printf("esp = %x\n", esp);
	return 0;
}

