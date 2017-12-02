#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
int matched[1001];
bool visited[1001];
vector<int> adj[1001];

bool dfs( int p) {
	visited[p] = true;
	for (int i : adj[p]) {
		if (!matched[i] || (!visited[matched[i]] && dfs(matched[i])) ) {
			matched[i] = p;
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		
		for (int i = 1; i <= m; i++) adj[i].clear();
		memset(matched, 0, sizeof(int) * (n + 1));

		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			for (int j = a; j <= b; j++) {
				adj[i].push_back(j);
			}
		}

		int result = 0;
		for (int i = 1; i <= m; i++) {
			if (dfs(i)) result++;
			memset(visited, 0, sizeof(bool) * (m + 1));
		}

		printf("%d\n", result);
	}

	return 0;
}