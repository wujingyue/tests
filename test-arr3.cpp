#include <iostream>
#include <cstdlib>
using namespace std;

const int max_n = 40000;

volatile int *a = new int[max_n * max_n];
// volatile int a[max_n][max_n];

int main() {
  for (int i = 0; i < max_n; ++i) {
    for (int j = 0; j < max_n; ++j) {
      a[i * max_n + j] = i + j;
      // a[i][j] = i + j;
    }
  }
  return 0;
}
