#include <stdio.h>
#include <string.h>
#define LAST_POINT n+m+1

int n, m;
int net[5102][5102];
int past_point[5102];
int visited[5102];
void back(int start) {
	if (start != 0) {
		int end = past_point[start];
		net[start][end]++;
		net[end][start]--;
		back(end);
	}
}
int dfs( int p) {
	if (p == LAST_POINT) return 1;
	visited[p] = 1;
	for (int i = 0; i <= LAST_POINT; i++) {
		if (net[p][i] && !visited[i]) {
			past_point[i] = p;
			if (dfs(i)) return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		net[0][i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		net[n + i][LAST_POINT] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		net[a][n+b] = 1;
	}

	int result = 0;
	while (dfs(0)) {
		result++;
		memset(visited, 0, sizeof(int) * (LAST_POINT + 1));
		back(LAST_POINT);
	}

	printf("%d", result);

	return 0;
}