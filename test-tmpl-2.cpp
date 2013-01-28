#include <iostream>
#include <cstdlib>
using namespace std;

#include "test-tmpl.h"


int main(int argc, char *argv[]) {
	A a;
	B b;
	a.val = atoi(argv[1]);
	b.val = atoi(argv[2]);
	cout << equal(a, b) << endl;
	return 0;
}
