// Four go Theorem ( 4색 정리 ) : 어떠한 평면 그래프도 최대 4 가지 색이면 인접한 노드 간 서로 다른 색으로 모두 칠할 수 있다.
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <vector> 

using namespace std;

#define MAX 100001 
#define COLOR 4
#define INF 987654321

vector<int> tree[MAX];
bool visited[MAX];
int dp[MAX][COLOR];

int go(int pos, int color) {
	int &ret = dp[pos][color];
	if (ret != -1) return ret;
	visited[pos] = true;
	ret = color;
	for (int i = 0; i < tree[pos].size(); i++) {
		if (visited[tree[pos][i]]) continue;
		int choose = INF;
		for (int j = 1; j <= 4; j++) {
			if (j != color) choose = min(choose, go(tree[pos][i], j));
		}
		ret += choose;
	}
	visited[pos] = false;
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	int ans = INF;
	for (int i = 1; i <= 4; i++) {
		ans = min(ans, go(1, i));
	}
	printf("%d\n", ans);
	return 0;
}