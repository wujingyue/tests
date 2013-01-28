#include <stdlib.h>
#include <stdlib.h>

void *foo(int *arg) {
  void *p = malloc(1024);
  void *q = arg;
  return p;
}

int main() {
  int a;
  foo((int *)foo(&a));
  return 0;
}
