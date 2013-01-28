#include <iostream>
using namespace std;

struct A {
	A(): val(0) {}
	int val;
};

struct B {
	B(): val(1) {}
	int val;
};

template <typename T>
void print(const T *ins) {
	cout << ins->val << endl;
}

int main() {
	A ins;
	print(&ins);
	return 0;
}
