#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int fair[1005];
int n;
int memo[1005];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &fair[i]);
	}


	memo[0] = 0;
	queue<int> next;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= j) {
				memo[i] = max(memo[i - j] + fair[j], memo[i]);
			}
		}
	}

	printf("%d\n", memo[n]);

	return 0;
}