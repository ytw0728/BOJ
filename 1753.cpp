/*
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

int v, e, s;
int dist[20001];
vector<vector<pair<int,int>>> adj;
bool chk[20001];
int cnt = 1;
void setting(int p) {
	cnt++;
	chk[p] = true;
	int index = -1;
	int min_value = INT_MAX;
	for (auto i : adj[p]) {
		dist[i.first] = min(dist[i.first], dist[p] + i.second);
	}

	for (int i = 1; i <= v; i++) {
		if (min_value > dist[i] && !chk[i]) {
			min_value = dist[i];
			index = i;
		}
	}
	if (index != -1) setting(index);
}

int main() {

	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) dist[i] = INT_MAX;

	scanf("%d", &s);

	adj.resize(v+1);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back( make_pair(v, w) );
	}
	
	dist[s] = 0;
	setting(s);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;

}
*/
// 우선순위 큐로. 시간초과 남.
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int v, e, s;
priority_queue<pair<int,int>> q; // d, index
vector<vector<pair<int,int>>> adj; // index, d
int dist[20001];

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) dist[i] = INT_MAX;

	scanf("%d", &s);
	dist[s] = 0;

	adj.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}

	q.push(make_pair(0,s));

	while ( !q.empty()) {
		int temp_d = -q.top().first;
		if ( temp_d <= dist[q.top().second]) {
			dist[q.top().second] = temp_d;
			for (auto i : adj[q.top().second]) {
				if ((temp_d + i.second) < dist[i.first]) {
					dist[i.first] = temp_d + i.second;
					q.push(make_pair(-dist[i.first], i.first));
				}
			}
		}
		q.pop();
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}







