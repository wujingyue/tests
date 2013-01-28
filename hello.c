#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);
  int b = a % 2;
  if (b) {
    a = a + 1;
	printf("hello world %d\n", a);
  }else {
	a = a + 2;
    printf("hello world %d\n", a);
  }
  return 0;
}
