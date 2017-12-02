#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dy[100000 + 1];
int v[100000 + 1];
int m;

void go(int p) {
	if (p > n) return;
	
	int& ret = dy[p];
	ret = max(dy[p - 1] + v[p], v[p]);

	m = m < ret ? ret : m;
	go(p + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	m = dy[1] = v[1];
	go(2);

	printf("%d", m);
	return 0;
}