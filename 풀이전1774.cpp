#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int parent[1005];
int rk[1005];
int linked[1005][1005];
pair<int, int> node[1005];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int uni(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return 0;
	if (rk[u] > rk[v]) {
		parent[u] = v;
	}
	else {
		parent[v] = u;
		if (rk[u] == rk[v])
			rk[u]++;
	}
	return 1;
}

typedef struct Edge {
	int a;
	int b;
	double c;

	bool operator <(Edge A)const { return c > A.c; }
}edge;
priority_queue<edge> E;

int main() {
	int n, m;
	int numNode = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[i] = make_pair(a, b);
		numNode++;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		linked[a][b] = linked[b][a] = 1;
		uni(a, b);
	}

	
	for (int i = 1; i <= numNode; i++) {
		for (int j = i + 1; j <= numNode; j++) {
			if (linked[i][j] ) continue;
			double distance = sqrt(pow((node[i].first - node[j].first), 2) + pow((node[i].second - node[j].second), 2));
			E.push({ i,j,distance });
		}
	}

	double ans = 0;
	int cnt = m;
	while (!E.empty() && cnt < n) {
		int t = uni(E.top().a, E.top().b);
		if (t) ans += E.top().c;
		E.pop();
	}


	printf("%.2lf\n", ans);
	return 0;
}