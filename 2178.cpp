#include <cstdio>
#include <queue>

using namespace std;

int map[105][105];
int dis[105][105];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	dis[1][1] = 1;
	queue<pair< int, int > > q;
	q.push({ 1,1 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i == x && j == y) continue;
				if (i != x && j != y) continue;
				if (map[i][j]) {
					if (!dis[i][j]) {
						dis[i][j] = dis[x][y] + 1;
						q.push({ i, j });
					}
					else dis[i][j] = dis[i][j] > dis[x][y] + 1 ? dis[x][y] + 1 : dis[i][j];
				}
			}
		}
	}

	printf("%d\n", dis[n][m]);

	return 0;
}