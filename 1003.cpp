#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> dp;

pair<int,int> go(int p) {
	if (p <= 0) {
		if (p == 0) {
			dp[0] = make_pair(1, 0);
			return dp[0];
		}
		return make_pair(0, 0);
	}
	if (p == 1) {
		dp[1] = make_pair(0, 1);
		return dp[1];
	}

	pair<int, int>& ret = dp[p];
	if (ret.first != 0 || ret.second != 0) return ret;

	ret.first = go(p - 2).first + go(p - 1).first;
	ret.second = go(p - 2).second + go(p - 1).second;

	return ret;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		dp.clear();
		dp.resize(n + 1);
		go(n);
		printf("%d %d\n", dp[n].first, dp[n].second);
	}
	return 0;
}