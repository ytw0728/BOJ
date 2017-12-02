#include <stdio.h>

int n;
int dy[1001];

int go(int p) {
	if (p > n) return 0;
	if (p == n) return 1;
	int& ret = dy[p];
	if (ret != 0) return ret;
	
	ret += go(p + 1);
	ret += go(p + 2);

	ret %= 10007;
	
	return ret;
}
int main() {
	scanf("%d", &n);
	go(0);
	printf("%d", dy[0]);

	return 0;
}