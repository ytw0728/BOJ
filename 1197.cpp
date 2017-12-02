/*
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

vector<pair<int,int>> adj[10001];
int v, e, s;
vector<int> routePoint;
bool chk[10001];

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
		if (!s) s = a;
	}

	routePoint.push_back(s);
	long long result = 0;

	while (routePoint.size() < v) {
		int minC = 987654321;
		int minIdx = 0, start = 0;
		for( auto p : routePoint ){
			chk[p] = true;
			for (auto i : adj[p]) {
				if ( !chk[i.first] && minC > i.second) {
					minC = i.second;
					start = p;
					minIdx = i.first;
				}
			}
		}
		if (minIdx && start) {
			chk[minIdx] = true;
			result += minC;
			//adj[start].erase( find(adj[start].begin(), adj[start].end(), minIdx) );
			routePoint.push_back(minIdx);
		}
		else {
			break;
		}
	}
	printf("%lld", result);
	return 0;
}
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int n_ = 1e4 + 1;
const int m_ = 1e5 + 1;

struct node {
	int u, v, c;
	bool operator <(node A)const { return c < A.c; }
} edg[m_];

int n, m;
int parent[n_];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void uni(int u, int v) {
	u = find(u), v = find(v);
	if (u > v) swap(u, v);
	if (u == v) return;
	parent[u] = v;
}

int main() {
	int i;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d %d", &edg[i].u, &edg[i].v, &edg[i].c);

	sort(edg + 1, edg + m + 1);

	long long ans = 0;
	for (i = 1; i <= n; i++) parent[i] = i;

	for (i = 1; i <= m; i++) {
		int u = find(edg[i].u), v = find(edg[i].v);
		if (parent[u] == parent[v]) continue;
		uni(u, v);
		ans += edg[i].c;
	}

	printf("%lld", ans);

	return 0;
}