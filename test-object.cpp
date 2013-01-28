#include <iostream>
using namespace std;

struct A {
  virtual void foo() {
    cout << "A::foo()\n";
  }

  int data;
};

struct B: public A {
  virtual void foo() {
    cout << "B::foo()\n";
  }
};

struct C: public A {
  virtual void foo() {
    cout << "C::foo()\n";
  }
};

void process(A *a) {
  a->foo();
}

int main() {
  A *ins1 = new B;
  A *ins2 = new C;
  process(ins1);
  process(ins2);
  return 0;
}
