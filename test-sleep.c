#include <stdio.h>
#include <unistd.h>

int main() {
  while (1) {
    fprintf(stderr, "sleeping...\n");
    sleep(1);
  }
  return 0;
}
