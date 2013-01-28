#include <stdio.h>

int main() {
	unsigned long a;
	scanf("%lu", &a);
	printf("%lu\n", (a >> 32));
	return 0;
}
