#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[100005];
int isBuilt[100005];
int indegree[100005];

void set(int now, int add) {
	for (auto i = adj[now].begin(); i != adj[now].end(); i++) {
		indegree[*i] += add;
	}
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int tmpM;
	tmpM = m;
	while (tmpM--) {
		int x,y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		indegree[y]++;
	}

	int tmpK = k;
	bool well = true;
	while (tmpK--) {
		int command, x;
		scanf("%d %d", &command, &x);
		if (!well) continue;

		command--;
		if (command) { // ÆÄ±«
			if (isBuilt[x]) {
				isBuilt[x]--;
				if( !isBuilt[x]) set(x, +1);
			}
			else well = false;
		}
		else { // °Ç¼³
			if (!indegree[x]) {
				if (!isBuilt[x]) set(x, -1);
				isBuilt[x]++;
			}
			else well = false;
		}
	}

	if (well) printf("King-God-Emperor\n");
	else printf("Lier!\n");
	return 0;
}