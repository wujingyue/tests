#include <stdio.h>
#include <stdlib.h>

struct S {
  long a;
  long b;
  long c;
};

volatile struct S s, t;

int main(int argc, char *argv[]) {
  s.a = atol(argv[1]);
  s.b = atol(argv[2]);
  s.c = atol(argv[3]);

  t = s;

  return 0;
}
