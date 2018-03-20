#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int dp[10005];

vector<int> coin;



int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));

		coin.clear();
		coin.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		
		int m;
		scanf("%d", &m);
		dp[0] = 1;

		for (auto i : coin) {
			for (int j = 0; j + i <= m; j++) {
				dp[j + i] += dp[j];
			}

		}

		printf("%d\n", dp[m]);
	}
	return 0;
}