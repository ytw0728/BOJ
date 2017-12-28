#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr[32001];
vector<int> sorted;
int check[32001];
int root[32001];

void dfs(int n) {
	check[n] = 1;

	if (!arr[n].empty()) {
		for (auto i = arr[n].begin(); i != arr[n].end(); i++) {
			if (check[*i] == 0) dfs(*i);
		}
	}
	sorted.push_back(n);
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	while (m--) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);

		arr[tmp1].push_back(tmp2);
	
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			dfs(i);
		}
	}

	while (!sorted.empty()) {
		printf("%d ", sorted.back());
		sorted.pop_back();
	}
	return 0;
}