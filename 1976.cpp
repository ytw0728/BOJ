#include <cstdio>
#include <algorithm>

using namespace std;

int rk[2005];
int parent[2005];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void uni(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (rk[u] > rk[v]) {
		parent[u] = v;
	}
	else {
		parent[v] = u;
		if (rk[u] == rk[v]) rk[u]++;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 2005; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			scanf("%d", &tmp);
			if( tmp ) uni(i, j);
		}
	}

	int last = -1;
	while (m--) {
		int city;
		scanf("%d", &city);
		if (last == -1) {
			last = find(city);
			continue;
		}
		if (last != find(city)) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}