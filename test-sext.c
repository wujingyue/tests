#include <stdio.h>

static const int n = 4;

int sext(int a) {
  if (a & (1 << (n - 1)))
    return a + (((1 << n) - 1) << n);
  return a;
}

int ok(int a, int b) {
  return sext((a + b) % (1 << n)) == (sext(a) + sext(b)) % (1 << (n * 2));
}

int main() {
  for (int a = 0; a < (1 << n); ++a) {
    for (int b = 0; b < (1 << n); ++b) {
      if ((a + b) & (1 << (n - 1)))
        continue;
      if ((a & (1 << (n - 1)) && (b & (1 << (n - 1)))))
        continue;
      if (!ok(a, b)) {
        printf("%d %d\n", a, b);
      }
    }
  }
  return 0;
}
