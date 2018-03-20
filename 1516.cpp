#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int buildTime[505];
vector<int> adj[505];
int n;
int dp[505];

int dfs(int now) {
	int &ret = dp[now];
	if (ret) return ret;

	int time = 0;
	for (auto i = adj[now].begin(); i != adj[now].end(); i++) {
		time = max(dfs(*i), time);
	}

	return ret = buildTime[now] + time;;
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &buildTime[i]);

		int tmp;
		while(~scanf("%d", &tmp) && tmp != -1){
			adj[i].push_back(tmp); // i 를 짓기 위한 tmp 들
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", dp[i]);
	}

	return 0;
}