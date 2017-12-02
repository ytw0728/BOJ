#include <stdio.h>

int dp[21][21][21];
int go(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return go(20, 20, 20);
	
	return dp[a][b][c];
}
int main() {
	int q, w, e;
	dp[0][0][0] = 1;
	for (q = 0; q <= 20; q++) {
		for (w = 0; w <= 20; w++) {
			for (e = 0; e <= 20; e++) {
				if (!q && !w && !e) continue;
				if (q <= 0 || w <= 0 || e <= 0) dp[q][w][e] = 1;
				else if (q < w && w < e) dp[q][w][e] = dp[q][w][e - 1] + dp[q][w - 1][e - 1] - dp[q][w - 1][e];
				else dp[q][w][e] = dp[q - 1][w][e] + dp[q - 1][w - 1][e] + dp[q - 1][w][e - 1] - dp[q - 1][w - 1][e - 1];
			}
		}
	}
	
	while (1) {
		scanf("%d %d %d", &q, &w, &e);
		if (q == -1 && w == -1 && e == -1) break;
		int result = go(q, w, e);
		printf("w(%d, %d, %d) = %d\n", q, w, e, result);
	}

	return 0;
}