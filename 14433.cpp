#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int k1, k2;
int ks[2][301][301];
int k_match[2][301];
bool visited[601];

bool dfs( int p, int t ) {
	visited[p] = true;
	for (int i = 1; i <= m; i++){
		if ( ks[t][p][i] && ( !k_match[t][i] || ( !visited[ k_match[t][i] ] && dfs( k_match[t][i] , t )) )) {
			k_match[t][i] = p;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k1, &k2);
	
	for (int i = 1; i <= k1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ks[0][a][b] = 1;
	}
	for (int i = 1; i <= k2; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ks[1][a][b] = 1;
	}

	int first_team = 0;
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + n + m + 1 + 1, 0);
		if (dfs(i,0)) first_team++;
	}

	int second_team = 0;
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + n + m + 1 + 1, 0);
		if (dfs(i,1)) second_team++;
	}


	if (first_team >= second_team) printf("그만 알아보자\n");
	else printf("네 다음 힐딱이\n");
	return 0;
}