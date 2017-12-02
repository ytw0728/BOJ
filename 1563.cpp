#include <stdio.h>
#define DIV 1000000
int n;
int dp[1001][2][3];

int go(int p, int cnt0, int cnt1) {
	if (p > n || cnt0 >= 2 || cnt1 >= 3) return 0;
	if (p == n) return 1;

	int& ret = dp[p][cnt0][cnt1];
	if (ret != 0) return ret;

	ret = go(p + 1, cnt0, 0)%DIV;
	if (cnt0 < 2) {
		ret += go(p + 1, cnt0 + 1, 0)%DIV;
	}
	if (cnt1 < 3) {
		ret += go(p + 1, cnt0, cnt1+1)%DIV;
	}

	return ret%DIV;
}

int main() {
	scanf("%d", &n);

	
	int result = go(0,0,0)%DIV;

	printf("%d", result);
	return 0;
}
