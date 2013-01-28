#include <iostream>
using namespace std;

struct Foo {
	static int a;
	Foo() {}
};

int Foo::a = 7;

int main() {
	Foo f;
	cerr << f.a << endl;
	return 0;
}

