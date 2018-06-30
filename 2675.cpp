#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp; scanf("%d", &tmp);
		string s;
		cin >> s;
		for (auto i : s) {
			for (int j = 0; j < tmp; j++) {
				printf("%c", i);
			}
		}
		printf("\n");
	}

	return 0;
}