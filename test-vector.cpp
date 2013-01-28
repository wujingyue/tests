#include <vector>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a, b;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  b.push_back(1);
  b.push_back(2);
  b.push_back(2);
  cout << (a == b) << endl;
  cout << (a < b) << endl;
  return 0;
}

