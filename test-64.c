#include <stdio.h>
#include <stdint.h>

int main() {
  // uint64_t b = 0xffffffffffffffffUL;
  uint64_t b = (uint64_t)(-1);
  unsigned a = b;
  printf("%u\n", a);
	return 0;
}

