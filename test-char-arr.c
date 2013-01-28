#include <stdio.h>

const char *SYNC_OP_NAMES[] = {
	"pthread_mutex_lock",
	"pthread_create",
};

int main() {
	printf("%d\n", sizeof(SYNC_OP_NAMES) / sizeof(const char *));
	return 0;
}

