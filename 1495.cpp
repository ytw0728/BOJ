#include <stdio.h>
#include <algorithm>

using namespace std;

int n, s, m;
int volumes[101];
bool dp[101][1001];

int main() {
	scanf("%d %d %d", &n, &s, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &volumes[i]);
	}

	dp[1][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!dp[i][j]) continue;
			if (j + volumes[i] <= m) dp[i + 1][j + volumes[i]] = true;
			if (j - volumes[i] >= 0) dp[i + 1][j - volumes[i]] = true;
		}
	}

	int result = -1;
	for (int i = m; i >= 0; i--) {
		if (dp[n+1][i]) {
			result = i;
			break;
		}
	}
	printf("%d", result);
	return 0;
}