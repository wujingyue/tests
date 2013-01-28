#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	int i;
	for (i = 0; i < 10000000; i++) {
		uid_t ret = getuid();
		if (ret == -1)
			exit(1);
	}
	return 0;
}

