#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t,n,b;

vector<pair<int,pair<int,int>>> maps_x[100000+1];
vector<pair<int,pair<int, int>>> maps_y[100000 + 1];

int go(int x,int y, int e, int p){
	if (p == n) return e-b;

	if (p != 1) e -= b;
	if (e < b) return -987654321;

	int result = 0;
	for (auto i = maps_x[x].begin(); i != maps_x[x].end(); i++) {
		if ((*i).first > y) result = max(result, go(x, (*i).first, e+(*i).second.first, (*i).second.second));
	}

	for (auto i = maps_y[y].begin(); i != maps_y[y].end(); i++) {
		if ((*i).first > x) result = max(result,go( (*i).first, y, e+(*i).second.first, (*i).second.second) );
	}

	return result;
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		maps_x->clear(); maps_y->clear();
		scanf("%d %d", &n, &b);
		int q, w, e;
		scanf("%d %d %d", &q, &w, &e);
		int s_x = q, s_y = w, s_e = e;
		maps_x[q].push_back( make_pair(w,make_pair(e,1) ));
		maps_y[w].push_back( make_pair(q,make_pair(e,1) ));
		for (int j = 2; j <= n; j++) {
			scanf("%d %d %d", &q, &w, &e);
			maps_x[q].push_back(make_pair(w, make_pair(e, j)));
			maps_y[w].push_back(make_pair(q, make_pair(e, j)));
		}

		int result = go(s_x,s_y,s_e, 1);
		printf("%d\n", result);
	}
	return 0;
}