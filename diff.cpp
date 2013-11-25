#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  assert(argc == 3);
  ifstream f1(argv[1]), f2(argv[2]);
  string s1, s2;
  unsigned long line = 0;
  while (true) {
    bool b1 = getline(f1, s1), b2 = getline(f2, s2);
    if (!b1 && !b2)
      return 0;
    if (!b1 || !b2 || s1 != s2) {
      cout << "differ at line " << line << endl;
      return 1;
    }
    line++;
  }
}
