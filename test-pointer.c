#include <stdio.h>

struct my_option {
  int data;
};

struct my_option my_long_options[1024];

int main() {
  printf("%lu\n", (&my_long_options[1]) - (&my_long_options[0]));
  return 0;
}
