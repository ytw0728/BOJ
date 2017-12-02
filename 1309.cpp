#include <stdio.h>
#define DIV 9901

int dp[100000+1][3]; // 0 left 1 right 2 empty
int n;

int main() {
	scanf("%d", &n);

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % DIV;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % DIV;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIV;
	}

	int result = (dp[n][0] + dp[n][1] + dp[n][2])%DIV;
	printf("%d\n", result);

	return 0;
}