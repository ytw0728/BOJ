#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dp[1010][4];
int map[1010][4];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
	dp[1][3] = map[1][3];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i-1][3] ) + map[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + map[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][3];
	}

	int result = min(dp[n][1], dp[n][2]);
	result = min(result, dp[n][3]);
	printf("%d", result);
	return 0;
}