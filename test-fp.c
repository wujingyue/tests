#include <stdio.h>

struct A {
  void*(*test)();
};

struct B {
  struct A *op;
};

void *test() {
  printf("TEST!\n");
  return NULL;
}

struct A a = {
  test,
};

struct B b = {
  &a,
};

void call(struct B *pb) {
  pb->op->test();
}

int main(int argc, char **argv) {
  call(&b);
  return 0;
}
