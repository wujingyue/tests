#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	vector<int> a;
	for (int i = 1; i < argc; ++i) {
		a.push_back(atoi(argv[i]));
	}
	cout << min(4UL, a.size()) << endl;
	return 0;
}
