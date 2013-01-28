#include <iostream>
#include <cstdio>
using namespace std;

struct A {
	virtual void foo() {
		printf("A::foo()\n");
	}
	virtual ~A() {}
};

struct B: public A{
	virtual void foo() {
		printf("B::foo()\n");
	}
};

int main() {
	A *a = new B();
	a->foo();
	delete a;
	return 0;
}
