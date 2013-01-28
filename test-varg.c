#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int n, ...) {
  va_list args;
  int s = 0;
  int i;
  va_start(args, n);
  for (i = 0; i < n; ++i) {
    s += va_arg(args, int);
  }
  va_end(args);
  return s;
}

int main(int argc, char *argv[]) {
  printf("%d\n", sum(3, 1, 2, 3));
  return 0;
}
