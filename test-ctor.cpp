#include <iostream>

using namespace std;

struct Type {
  Type() {
    cout << "Type\n";
  }
  ~Type() {
    cout << "~Type\n";
  }
};

void dtor() {
  cout << "dtor\n";
}

Type t;

int main() {
  exit(0);
}
