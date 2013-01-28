#include <stdio.h>
#include <pthread.h>

int main() {
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	size_t stack_size;
	pthread_attr_getstacksize(&attr, &stack_size);
	printf("Default stack size = %lu\n", stack_size);
	return 0;
}

