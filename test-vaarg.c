#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...) {
  va_list vl;
  int i;
  int result = 0;

  va_start(vl, n);
  for (i = 0; i < n; ++i) {
    int value = va_arg(vl, int);
    result += value;
  }
  va_end(vl);

  va_start(vl, n);
  for (i = 0; i < n; ++i) {
    int value = va_arg(vl, int);
    result += value;
  }
  va_end(vl);

  return result;
}

int main() {
  int (*fp)(int, ...) = sum;
  printf("%d\n", fp(5, 1, 2, 3, 4, 5));
  return 0;
}
