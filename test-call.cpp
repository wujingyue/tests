#include <iostream>
#include <cstdlib>
using namespace std;

void foo(int *a, int *b) {
  *a = 1;
  *b = 2;
}

int main() {
  int a = 0, b = 0;
  foo(&a, &b);
  foo(&b, &a);
  return 0;
}
