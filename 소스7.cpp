#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

float posi[1001];
float dp[1001];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%f", &posi[j]);
		}
		dp[1] = posi[1];
		dp[2] = max(dp[1], posi[2]);
		dp[3] = max(max(dp[1], dp[2]), posi[3]);

		for (int j = 3; j <= n; j++) {
			dp[j] = max(max(dp[j - 3] + posi[j], dp[j - 2]),dp[j-1] );
		}
		printf("%.1f\n", dp[n]);
	}
	return 0;
}