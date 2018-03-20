#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[1000005];
int n;

int main() {
	scanf("%d", &n);

	dp[0] = 1;
	for (int i = 1; i <= n; i *= 2){
		for (int j = 0; i + j <= n; j++) {
			dp[i + j] += (dp[j]% 1000000000);
			dp[i + j] %= 1000000000;
		}
	}

	printf("%d\n", dp[n]%1000000000);
	return 0;
}