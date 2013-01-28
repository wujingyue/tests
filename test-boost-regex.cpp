#include <boost/regex.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace boost;

void print_usage(int argc, char *argv[]) {
	fprintf(stderr, "%s <a string>\n", argv[0]);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		print_usage(argc, argv);
		exit(1);
	}
	const regex e("#.*");
	cout << regex_replace(string(argv[1]), e, "") << endl;
	return 0;
}

