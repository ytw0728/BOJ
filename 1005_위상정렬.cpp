#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

vector<vector<int>> edge;
vector<int> arr_t;

int last_point;
int n;
int done;

int dp[1001];
int dfs(int s) {
	int& ret = dp[s];

	if (ret > 0) return ret;
	for (auto i : edge[s]) {
		ret = max(ret, dfs(i));
	}

	ret += arr_t[s];
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	int k;
	for (int i = 0; i < t; i++) {

		scanf("%d %d", &n, &k);
		arr_t.clear();
		edge.clear();
		arr_t.resize(n + 1);
		edge.resize(n + 1);

		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr_t[j]);
		}

		for (int j = 1; j <= k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			edge[b].push_back(a);
		}

		scanf("%d", &last_point);
		int result = dfs(last_point);

		printf("%d\n",result);

		memset(dp, 0, (n+1) * sizeof(int));
	}
	return 0;
}