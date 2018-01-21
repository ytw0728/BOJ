#include <string>
#include <iostream>

using namespace std;

int main() {

	string str;
	cin >> str;

	auto end = str.end();
	end -= str.length() / 2;

	auto j = str.end() - 1;

	int done = 1;
	for (auto i = str.begin(); i != end + 1; i++, j--) {
		if (*i != *j) {
			done = 0;  break;
		}
	}

	cout << done << endl;


	return 0;
}