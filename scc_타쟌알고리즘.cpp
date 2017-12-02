#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
const int v_ = 1e4 + 1;

int v, e, cnt, pos, scc[v_], chk[v_], stk[v_];
vi gph[v_];
vector<vi> res;

int dfs(int now) {
	chk[now] = ++cnt;
	int ret = chk[now];
	stk[pos++] = now;
	for (int nxt : gph[now]) {
		if (!chk[nxt]) ret = min(ret, dfs(nxt));
		else if (!scc[nxt]) ret = min(ret, chk[nxt]);
	}

	if (ret != chk[now]) return ret;

	res.push_back(vi());
	while (1) {
		int top = stk[--pos];
		scc[top] = res.size();
		res[scc[top] - 1].push_back(top);
		if (top == now) break;
	}

	return ret;
}

int main() {
	int i;

	scanf("%d %d", &v, &e);
	for (i = 1; i <= e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		gph[a].push_back(b);
	}

	for (i = 1; i <= v; i++)
		if (!chk[i]) dfs(i);

	for (auto &i : res) sort(i.begin(), i.end());
	sort(res.begin(), res.end(), [](const vi &i, const vi &j) { return i[0] < j[0]; });

	printf("%d\n", res.size());
	for (auto &i : res) {
		for (auto j : i) printf("%d ", j);
		puts("-1");
	}

	return 0;
}