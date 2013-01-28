#include <stdio.h>

#include "test-arr.h"

int arr[10] = {0};

int main() {
  int i;
  init_arr();
  printf("flag = %d\n", flag);
  for (i = 0; i < 10; ++i)
    printf("%d\n", arr[i]);
  return 0;
}
