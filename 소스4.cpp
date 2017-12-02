#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> arr;
int visited[101];
int finish[101];
int n;
int cycle;
void dfs(int s) {
	visited[s] = 1;
	for (auto t : arr[s]) {
		if ( !visited[t]) dfs(t);
		else if (!finish[t]) cycle = 1;
	}
	finish[s] = 1;
}
int main() {
	int k;
	scanf("%d", &n);
	arr.resize(n);
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}

	dfs(0);
	if (cycle) printf("cycle");
	else printf("none");
	return 0;
}