#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int amount[10001];
int dy[10001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &amount[i]);
	}

	dy[1] = amount[1];
	dy[2] = amount[1] + amount[2];

	for (int i = 3; i <= n; i++) {
		dy[i] = max( dy[i-3]+ amount[i-1]+amount[i], dy[i - 2] + amount[i]);
		dy[i] = max(dy[i], dy[i - 1]);

	}

	printf("%d", dy[n]);
	return 0;
}

