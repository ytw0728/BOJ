#include <cstdio>
#include <queue>

using namespace std;

int parent[1005];
int rk[1005];

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
	int c;

	bool operator <(Edge A)const { return c > A.c; }
}edge;

priority_queue<edge > E;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) parent[i] = i;

	int tmpM = m;
	while (tmpM--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edge tmp = { a, b, c };
		E.push(tmp);
	}

	long long ans = 0;
	int cnt = 0;

	while (!E.empty() && cnt < n) {
		int t = uni(E.top().a, E.top().b);
		if (t) {
			ans += E.top().c;
			cnt++;
		}
		E.pop();
	}


	printf("%lld\n", ans);

	return 0;
}