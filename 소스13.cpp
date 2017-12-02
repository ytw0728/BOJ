#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


int main() { 
	int t;
	scanf("%d",&t);
	for (int q = 0; q < t; q++) {
		vector<vector<int>> adj;
		priority_queue<pair<int, int>> qu;
		int value[10001];
		bool visited[10001];
		int n, m;
		scanf("%d %d", &n, &m);
		adj.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			int many, need;
			scanf("%d %d", &many, &need);
			qu.push(make_pair( -(many-need), i));
			value[i] = many - need;
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int cost = 0;
		queue<int> bfs_q;
		while ( !qu.empty() ) {
			if ( qu.top().first <= 0) break;
			int t = -qu.top().first;
			
			
			int point = qu.top().second;
			bfs_q.push(point);
			
			while (!bfs_q.empty()){
				visited[bfs_q.front()] = true;
				if (value[bfs_q.front()] >= 0) {
					bfs_q.pop();
					break;
				}
				for (auto i : adj[point]) if( !visited[i] ) bfs_q.push(i);

			} 

		}
	}
	return 0;
}