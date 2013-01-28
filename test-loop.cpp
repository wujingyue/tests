#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; ++i) {
    cout << "hello world\n";
    sleep(1);
  }
  exit(0);
}
