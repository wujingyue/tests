#include <iostream>
#include <cstdlib>

using namespace std;

class Item {
 public:
  virtual int type() const = 0;
};

class Item1: public Item {
 public:
  int type() const {
    return 1;
  }
};

class Item2: public Item {
 public:
  int type() const {
    return 2;
  }
};

void print_item(Item *a, Item *b) {
  cout << a->type() << "\n";
  cout << b->type() << "\n";
}

int main(int argc, char *argv[]) {
  Item *a;
  if (atoi(argv[1]) == 1) {
    a = new Item1();
  } else {
    a = new Item2();
  }
  print_item(a, a);
  return 0;
}
