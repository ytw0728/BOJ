#include <cstdio>
#include <queue>

using namespace std;

int parent[100005];
int rk[100005];
int chk[100005];

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

priority_queue< edge > E;
vector<edge> edges;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;

	int tmpM = m;
	while (tmpM--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edge tmp = { a,b,c };
		E.push(tmp);
	}

	long long ans = 0;
	int biggest = 0;
	int cnt = 0;

	while (!E.empty() && cnt < n) {
		int t = uni(E.top().a, E.top().b);
		if (t) {
			ans += biggest = E.top().c;
	//		chk[E.top().a]++; chk[E.top().b]++;
	//		edges.push_back(E.top());
			cnt++;
		}
		E.pop();
	}
	/*
	int biggest = 0;
	for (auto i = edges.begin(); i != edges.end(); i++) {
		int a = (*i).a, b = (*i).b;
		if (chk[a] >= 2 && chk[b] >= 2) biggest = biggest < (*i).c ? (*i).c : biggest;
	}
	*/

	printf("%lld\n", ans - biggest); // biggest가 leaf 로 가는 경로일 때까지 처리하기. <= nono 안해도 된다. 집 하나도 마을이라고 한다.

	return 0;
}