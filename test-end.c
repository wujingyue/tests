#include <stdio.h>

extern char end[];

int main() {
	printf("%x\n", (int)end);
	return 0;
}

