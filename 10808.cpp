#include <iostream>
#include <string>

using namespace std;

int chk[30];

int main() {
	string s;
	cin >> s;
	for (auto i : s) {
		chk[i - 'a']++;
	}

	for (int i = 0; i <= 'z' - 'a'; i++) printf("%d ", chk[i]);
	return 0;
}