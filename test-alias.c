#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct A {
	short a;
};

struct B {
	int a;
	int b;
};

void foo(struct A *c) {
	c->a = 1;
}

int main(int argc, char *argv[]) {
	struct B ins;
	foo((struct A *)&ins);
	return 0;
}
