#include <cstdio>

using namespace std;

int dp[1005][4];
int n;

int go(int s, int t) {
	if (s < 0) return 0;
	if (s == 0) return 1;

	int &ret = dp[s][t];
	if (ret) return ret%10007;

	ret = go(s - 1, 1) + go(s - 2, 2) + go(s - 2, 3);

	return ret % 10007;
}

int main() {
	scanf("%d", &n);
	int result = go(n, 0);

	result %= 10007;

	printf("%d", result);
	return 0;
}