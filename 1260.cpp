#include <stdio.h>
#include <queue>

int vertex, line, starting;
int data[1001][1001] = { 0, };
int chk[1001] = { 0, };
void dfs(int s) {
	if (chk[s]) return;
	chk[s] = 1;
	printf("%d ", s);
	for (int i = 1; i <= vertex; i++) {
		if (data[s][i]) {
			dfs(i);
		}
	}
}

std::queue<int> queue;
void bfs(int s) {
	queue.push(s);
	chk[s] = 1;
	while (!queue.empty()) {
		printf("%d ", queue.front() );
		for (int i = 1; i <= vertex; i++) {
			if (data[queue.front()][i] && !chk[i]) {
				chk[i] = 1;
				queue.push(i);
			}
		}
		queue.pop();
	}
}

int main() {
	int x, y;

	scanf("%d %d %d", &vertex, &line, &starting);
	for (int i = 0; i < line; i++) {
		scanf("%d %d", &x, &y);
		data[x][y] = data[y][x] = 1;
	}
	dfs(starting);
	printf("\n");

	for (int i = 1; i <= vertex; i++) chk[i] = 0;

	bfs(starting);

	return 0;
}