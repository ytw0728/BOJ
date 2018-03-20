#include <cstdio>
#include <algorithm>

using namespace std;


int parent[1000005];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void uni(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (u > v) swap(u, v);
	parent[u] = v;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int tmpM = m;
	
	while (tmpM--) {
		int which;
		int a, b;
		scanf("%d %d %d", &which, &a, &b);
		if (!parent[a]) parent[a] = a;
		if (!parent[b]) parent[b] = b;

		if (which) {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else {
			uni(a, b);
		}

	}
	return 0;
}