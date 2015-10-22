#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	unsigned short cols = 80;
	if (argc > 1) {
		stringstream ss;
		ss << argv[1];
		if (!(ss >> cols)) {
			cerr << "Bad argument!\n";
			return 1;
		}
	}
	string line;
	while (getline(cin, line)) {
		if (line.length() < (cols - 1)) {
			unsigned short pad = (cols - line.length()) / 2;
			do
				line.insert(line.begin(), ' ');
			while (--pad);
		}
		cout << line << '\n';
	}
	return 0;
}