#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>

__thread int a = 0;

int main() {
  a = 1;
  fork();
  printf("a = %d after fork\n", a);
	return 0;
}
