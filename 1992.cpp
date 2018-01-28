#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char map[100][100];
string result;

void go(int n, int x, int y) {
	if (n == 1) {
		result.push_back(map[x][y]);
		return;
	}

	int firstV = map[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (firstV != map[i][j]) {
				result.push_back('(');
				for (int q = 0; q < 2; q++) {
					for (int k = 0; k < 2; k++) {
						go(n / 2, x + q*n / 2, y + k*n / 2);
					}
				}
				result.push_back(')');
				return;
			}
		}
	}
	result.push_back(firstV);
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	go(n, 0, 0);

	cout << result;

	return 0;
}