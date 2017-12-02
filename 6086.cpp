// 포드 풀커슨 알고리즘 /  에드몬드 카프 알고리즘

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LAST_POINT 'Z'-'A'+1
#define WHOLE 'z' - 'a' + 'Z' - 'A' + 2

using namespace std;

int pipes[WHOLE+1][WHOLE+1];
int visited[WHOLE+1];
int past_point[WHOLE+1];

void back(int start, int water) {
	if (start != 1) {
		int end = past_point[start];
		pipes[start][end] += water;
		pipes[end][start] -= water;
		back(end,water);
	}
}
int dfs( int p, int water) {
	if (p == LAST_POINT) return water;
	visited[p] = 1;
	int temp_water = water;
	for (int i = 1; i <= WHOLE; i++) {
		temp_water = water;
		if (pipes[p][i] > 0 && !visited[i]) {
			temp_water = min(water, pipes[p][i]);
			past_point[i] = p;
			int temp = 0;
			if ( temp = dfs(i,temp_water) ) {
				return temp;
			}
		}
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b; int c;
		scanf(" %c %c %d", &a, &b, &c);

		if ('A' <= a && a <= 'Z') a = a - 'A' + 1;
		else a = a - 'a' + 1 + 26;
		if ('A' <= b && b <= 'Z') b = b - 'A' + 1;
		else b = b - 'a' + 1 + 26;

		pipes[a][b] += c;
	}

	int result = 0;
	int temp = 0;
	while ( temp = dfs(1, 1000)) {
		result += temp;
		memset(visited, 0, sizeof(int) * (WHOLE + 1));
		back(LAST_POINT,temp);
	}

	printf("%d", result);

	return 0;
}