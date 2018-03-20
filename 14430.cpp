#include <cstdio>
#include <algorithm>

using namespace std;


int map[505][505];
int dp[505][505][3]; // 1 오른쪽 // 2 아래 

int n, m;

int go(int x, int y, int t) {
	if (x > n || y > m) return 0;
	if (x == n && y == m) return map[x][y];

	int &ret = dp[x][y][t];
	if (ret) return ret;

	ret = max( go(x + 1, y, 2), go(x, y + 1, 1) ) + (map[x][y]? 1:0);

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int result = go(0, 0, 0);

	printf("%d", result);
	return 0;
}