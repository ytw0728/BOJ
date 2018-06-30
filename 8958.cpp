#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		string s;
		cin >> s;
		int sum = 0;
		int point = 0;
		for (auto i : s) {
			if (i == 'X') point = 0;
			else point++;
			sum += point;
		}

		printf("%d\n", sum);
	}
	return 0;
}