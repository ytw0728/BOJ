#include <stdio.h>

int n, m;
long long dy[31][31]; // dy[m][n];

long long go(int n, int r) {
	if (n < 0 || r < 0) return 0;
	if (n == r || r == 0) {
		dy[n][r] = 1;
		return 1;
	}
	
	long long& ret = dy[n][r];
	if (ret != 0) return ret;
	if (r == 0) {
		ret += go(n - 1, r);
	}
	else if (r == n) {
		ret += go(n - 1, r - 1);
	}
	else {
		ret += go(n - 1, r - 1) + go(n - 1, r);
	}

	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	dy[0][0] = 1;
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		long long result = go(m, n);
		printf("%lld\n", result);
	}
	return 0;
}