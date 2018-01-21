#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	string tmp;
	cin >> tmp;
	

	long long v = 0;
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		v += (*i - '0');
	}
	


	cout << v << endl;
	return 0;
}