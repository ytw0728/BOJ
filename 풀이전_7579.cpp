#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int ms[101];
int c[101];
int cost_sum = 0;
int dp[11001];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= 11000; i++) dp[i] = -1;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &ms[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		cost_sum += c[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10001; j++) {
			if (dp[j] != -1 && dp[ j + c[i] ] < dp[j] + ms[i]) {
				dp[ j + c[i] ] = dp[j] + ms[i];
			}
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m) {
			printf("%d", i); 
			break;
		}
	}
		
	return 0;
}

