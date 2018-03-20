#include <cstdio>
#include <queue>

using namespace std;

typedef struct Node {
	int w;
	int u;
	int v;
	bool operator<(Node A)const {
		return w > A.w;
	}
}node;

priority_queue<node> q;

int plant[1005];
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

int chk[1005];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		scanf("%d", &plant[i]);
		chk[plant[i]] = 2;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		q.push({ c,a,b });
	}

	for (int i = 1; i <= n; i++) parent[i] = i;

	int cnt = 0;
	long long ans = 0;
	long long minus = 0;

	while (!q.empty() && cnt < n ){
		int t = uni(q.top().u, q.top().v);

		if (t) {
			if (chk[q.top().u] >= 2 && chk[q.top().v] >= 2) minus += q.top().w;
			ans += q.top().w;

			chk[q.top().u]++;
			chk[q.top().v]++;
		}
		q.pop();
	}

	printf("%lld\n", ans - minus);

	return 0;
}