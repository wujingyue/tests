#include <stdio.h>
#include <assert.h>

int main() {
  char *line = NULL;
  size_t n = 0;
  assert(getline(line, &n, stdin) >= 0);
  printf("#%s#\n", line);
  return 0;
}
