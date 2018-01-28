#include <cstdio>

using namespace std;

int map[3000][3000];
int cnt[3]; // 0 => -1 , 1 => 0 , 2 => 1

void go(int n, int x, int y) {
	if (n == 1) {
		cnt[map[x][y] + 1]++;
		return;
	}

	int firstV = map[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (firstV != map[i][j]) {
				for (int q = 0; q < 3; q++) {
					for (int k = 0; k < 3; k++) {
						go(n / 3, x + q*n / 3, y + k*n / 3);
					}
				}
				return;
			}
		}
	}
	cnt[firstV + 1]++;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	go(n, 0, 0);


	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}