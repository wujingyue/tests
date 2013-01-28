#include <stdio.h>

void foo(const char *str) {
	fprintf(stderr, "%s\n", str);
}

int main(int argc, char *argv[]) {
	foo("wujingyue");
	return 0;
}
