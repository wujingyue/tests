#include <stdio.h>
#include <stdlib.h>

const char *ga = "1234567\0";
const char *gb = "7654321\0";

int main(int argc, char *argv[]) {
  int la = atoi(argv[1]), lb = atoi(argv[2]);
  char *a = (char *)malloc(la);
  char *b = (char *)malloc(lb);
  printf("[%p, %p)\n[%p, %p)\n", a, a + la, b, b + lb);
  free(a);
  free(b);
  printf("ga = %p\ngb = %p\n", ga, gb);
  return 0;
}
