#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int coin[101];
int dy[101];

int go(int p) {
	if (p > n) return 0;
	int& ret = dy[p];
	if (ret != 0) return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + n - 1);

	go(1);

	return 0;
}