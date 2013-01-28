#include <stdio.h>
#include <stdlib.h>

int n = 10;

int main(int argc, char *argv[]) {
	int i;
	if (argc >= 2)
		n = atoi(argv[1]);
#if 0
	void *a[10];
	for (i = 0; i < n; ++i)
		a[i] = malloc(sizeof(int));
#endif
	for (i = 0; i < n; ++i)
		printf("abc\n");
	return 0;
}
