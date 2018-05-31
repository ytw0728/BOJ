#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[20005];
vector<int> answer[20005];
bool chk[20005];


int main() {
	int n, m , start = 1;
	int maxDistance = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<pair<int,int> > q; // 번호, 거리
	q.emplace(1,0);
	chk[1] = true;

	while (!q.empty()) {
		int now = q.front().first, distance = q.front().second; q.pop();
		for (auto i = adj[now].begin(); i != adj[now].end(); i++) {
			if (chk[*i]) continue;
			chk[*i] = true;
			maxDistance = distance + 1;
			q.emplace(*i, maxDistance);
			answer[maxDistance].push_back(*i);
		}
	}

	sort( answer[maxDistance].begin(), answer[maxDistance].end());
	printf("%d %d %d\n", answer[maxDistance][0], maxDistance, answer[maxDistance].size());
	return 0;
}