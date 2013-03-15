#include <gmpxx.h>
#include <iostream>

int main() {
  mpz_class a("123");
  mpz_class b("456");
  std::cout << a * b << "\n";
}
