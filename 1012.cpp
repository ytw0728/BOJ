#include <cstdio>
#include <queue>

using namespace std;

int map[55][55];
queue<pair< int, int> > q;
int n, m, k;

void go(int a, int b) {
	map[a][b] = 0;
	for (int i = a - 1; i <= a + 1; i++) {
		for (int j = b - 1; j <= b + 1; j++) {
			if (i == a && j == b || i != a && j != b) continue;
			if (0 <= i && i < n && 0 <= j && j < m && map[i][j]) {
				go(i, j);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		
		while (!q.empty() ) q.pop();

		scanf("%d %d %d", &n, &m, &k);
		while (k--) {
			int a, b;
			scanf("%d %d", &a, &b);
			map[a][b] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					go(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}