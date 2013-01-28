#include <iostream>
using namespace std;

namespace a {
	int test = 1;
}

namespace b {
	int test = 2;
}
using namespace b;

int main() {
	cout << test << endl;
	return 0;
}
