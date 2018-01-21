#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> result;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		string str;
		cin >> str;
		string tmp = str;


		if ( next_permutation(str.begin(), str.end()) ) cout << str << endl;
		else cout << "BIGGEST"<< endl;
	}

	return 0;
}