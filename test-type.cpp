#include <iostream>

using namespace std;

void foo(int a) {
  cout << a << "\n";
}

void foo(bool a) {
  cout << (a ? "true\n" : "false\n");
}

int main() {
  foo(1);
  foo(3 < 2);
  return 0;
}
