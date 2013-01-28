#include <stdio.h>

#define foo(x) (x)
#define foo(x, y) (x + y)

int main() {
  printf("%d\n", foo(1));
  printf("%d\n", foo(1, 2));
	return 0;
}
