#include <cstdio>

using namespace std;

long long dp[70][11];
long long result[70];

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i <= 10; i++) dp[1][i] = 1;
	for (int i = 1; i <= 64; i++) {
		long long sum = 0;
		for (int j = 1; j <= 10; j++) {
			sum += (dp[i][j] = dp[i][j - 1] + dp[i - 1][j]);
		}
		result[i] = sum;
	}
	while (T--) {
		int n; scanf("%d", &n);
		printf("%lld\n", result[n]);
	}
	return 0;
}