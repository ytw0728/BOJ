#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
string t;
int main() {
	cin >> s;
	cin >> t;
	long a;
	do {
		int n = 0;
		while (s.front() == t.front() ) {
			n++;
		}
		if (n) {
			string q = s.substr(n);
			cout << s.erase(n, q.length());
			s = q;
		}
		a = s.find(t);
		if (a <= s.length()) {
			s.erase(a, t.length());
		}
	} while (a <= s.length());
	cout << s;
	return 0;
}