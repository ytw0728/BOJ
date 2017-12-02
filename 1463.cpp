#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1000001];
int go(int p) {
	if (p == 1) return 0;
	if (p < 1) return 987654321;

	int& ret = dp[p];
	if (ret != 0) return ret;
	
	ret = 987654321;

	if (!(p % 3)) ret = go(p / 3) + 1;
	if (!(p % 2)) ret = min(ret, go(p / 2) + 1 );
	if (p - 1 >= 1) ret = min(ret, go(p - 1) + 1);

	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	int result = go(n);
	printf("%d", result);
	return 0;
}