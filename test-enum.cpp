#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;

enum Type {
  A,
  B,
  C
};

int main(int argc, char *argv[]) {
  Type t;
  fread(&t, sizeof(Type), 1, stdin);
  assert(t == A || t == B || t == C);
  cout << hex << t << "\n";
  switch (t) {
    case A: cout << "A\n"; break;
    case B: cout << "B\n"; break;
    case C: cout << "C\n"; break;
  }
  return 0;
}
