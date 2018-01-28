#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <set>

#define PIG_START n
#define LAST_POINT n+m+1
#define MAX_SIZE n+m+2

using namespace std;

vector<set<int>> adj;
int ptVal[1100+ 10][1100 + 10];

int m, n;

bool done = false;

bool dfs(int p) {
	if ( p == LAST_POINT ) {
		done = true;
		return true;
	}
	int index;
	for (auto next : adj[p] ) {
		if( ptVal[p][next] > 0 && dfs(next)) {
			index = next;
			break;
		}
	}
	if (done) {
		ptVal[p][index]--;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	scanf("%d %d", &m, &n);

	adj.resize(MAX_SIZE);

	for (int i = 1; i <= m; i++) {
		int temp;
		scanf("%d", &temp);
		adj[PIG_START + i].insert(LAST_POINT);
		ptVal[PIG_START + i][LAST_POINT] = temp;
	}

	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		for (int q = 0; q < t; q++) {
			int now;
			scanf("%d", &now);
			adj[i].insert(PIG_START + now);
			ptVal[i][PIG_START + now] = MAX_SIZE;
		}

		int last;
		scanf("%d", &last);
		adj[0].insert(i);
		ptVal[0][i] = last;
	}

	int result = 0;
	while (dfs(0)) {
		result++;
		done = false;
	}

	printf("%d", result);

	return 0;
}		