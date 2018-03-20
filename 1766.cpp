#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> adj[32005];
int indegree[32005];
vector<int> answer;

int n, m;

priority_queue<int, vector<int>, greater<int> > Q;
void bfs() {

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int now = Q.top();
		Q.pop();
		answer.push_back(now);

		for (auto i = adj[now].begin(); i != adj[now].end(); i++) {
			indegree[*i]--;
			if (!indegree[*i]) {
				Q.push(*i);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	int tmpM = m;
	while (tmpM--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}

	bfs();
	

	for (auto i = answer.begin(); i != answer.end(); i++) printf("%d ", *i);
	return 0;
}