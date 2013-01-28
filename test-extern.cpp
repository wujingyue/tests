#include <iostream>

using namespace std;

extern "C" void print();

void print() {
  cout << "hello world\n";
}

int main() {
  print();
  return 0;
}
