#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;
int v, e;
vector<vector<int>> edge;
vector<vector<int>> rev_edge;
priority_queue<pair<int,int>> finish_time;
vector<vector<int>> cycles;
vector<int> temp;

bool chk[10001];
int cnt = 0;
void dfs(int p) {
	chk[p] = true;
	for (auto i : edge[p]) {
		if (!chk[i]) dfs(i);
	}
	cnt++;
	finish_time.push(make_pair(cnt, p));
}

void rev_dfs(int p) {
	chk[p] = true;
	for (auto i : rev_edge[p]) {
		if (!chk[i]) rev_dfs(i);
	}
	temp.push_back(p);
}
int main() {
	scanf("%d %d", &v, &e);
	int a, b;
	int starting = -1;

	edge.resize(v + 1);
	rev_edge.resize(v + 1);

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		rev_edge[b].push_back(a);
	}

	for(int i = 1 ; i <= v; i++){
		if (!chk[i]) {
			dfs(i);
		}
	}

	memset(chk, 0, v+1);

	while(!finish_time.empty()) {
		if (!chk[finish_time.top().second]) {
			rev_dfs(finish_time.top().second);
			if (!temp.empty()) {
				sort(temp.begin(), temp.end());
				cycles.push_back(temp);
				temp.clear();
			}
		}
		finish_time.pop();
	}
	

	printf("%d\n", cycles.size());
	sort(cycles.begin(), cycles.end());
	for (auto i = cycles.begin(); i != cycles.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			printf("%d ", *j);
		}
		printf("-1\n");
	}
	return 0;
}