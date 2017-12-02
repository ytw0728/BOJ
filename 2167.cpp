#include <stdio.h>

int arr[301][301];
int dy[301][301];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += arr[i][j];
			dy[i][j] = sum + dy[i-1][j];
		}
	}
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int answer = dy[c][d] - dy[a - 1][d] - dy[c][b - 1] + dy[a - 1][b - 1];
		printf("%d\n", answer);
	}
	
	return 0;
}