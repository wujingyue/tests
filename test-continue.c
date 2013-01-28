#include <stdio.h>

int main() {
	int i = 0;
	do {
		++i;
		if (i > 0)
			continue;
	} while (i < 5);
	printf("%d\n", i);
	return 0;
}

