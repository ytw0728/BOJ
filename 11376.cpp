#include <stdio.h>
#include <string.h>
#define LAST_POINT n+m+1

int n, m;
int link[2002][2002]; // 0 start point  n+m+1 last point
int visited[2002];
int past_point[2002];

void back(int start) {
	if (start != 0) {
		int end = past_point[start];
		link[start][end]++;
		link[end][start]--;
		back(end);
	}
}

int dfs(int p) {
	if (p == LAST_POINT) return 1;
	visited[p] = 1;
	for (int i = 0; i <= LAST_POINT; i++) {
		if (link[p][i] > 0 && !visited[i]) {
			past_point[i] = p;
			if (dfs(i)) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		link[0][i] = 2;
	}

	for (int i = 1; i <= m; i++) {
		link[n + i][LAST_POINT] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int nums;
		scanf("%d", &nums);
		for (int j = 0; j < nums; j++) {
			int temp;
			scanf("%d", &temp);
			link[i][n + temp] = 1;
		}
	}
	int result = 0;

	while (dfs(0)) {
		memset(visited, 0, sizeof(int) * (LAST_POINT + 1));
		result++;
		back(LAST_POINT);
	}
	printf("%d\n", result);

	return 0;
}