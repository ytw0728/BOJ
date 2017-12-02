#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int c, m;
vector<pair<int,int>> cost[100000 + 1];

int go(int p, int cos) {

	int result = cos;
	for (auto i = cost[p].begin(); i != cost[p].end(); i++) {
		result = max(result , go( (*i).first, cos + (*i).second) );
	}
	if (result < m) return -1;
	else return result;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &c, &m);
		int s, d, co;
		for (int j = 2; j <= c; j++) {
			scanf("%d %d %d", &s, &d, &co);
			cost[s].push_back( make_pair(d, co) );
		}
		
		int result = go(1,0);
		printf("%d\n", result);

		for (int j = 0; j <= c; j++) cost[j].clear();
	}
	return 0;
}