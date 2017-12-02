#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define LAST_POINT n+m+1

using namespace std;

int n, m, k;
int link[2002][2002]; // 0 start point  n+m+1 last point
int link_temp[2002][2002]; // 0 start point  n+m+1 last point
int visited[2002];
int past_point[2002];
vector<pair<int,vector<int>>> skill_sets;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
	if (a.second.size() > b.second.size() ) return 1;
	else return 0;
}
void back(int start) {
	if (start != 0) {
		int end = past_point[start];
		link[start][end]++;
		link[end][start]--;
		back(end);
	}
}

int dfs(int p) {
	if (p == LAST_POINT) return 1;
	visited[p] = 1;
	for (int i = 0; i <= LAST_POINT; i++) {
		if (link[p][i] > 0 && !visited[i]) {
			past_point[i] = p;
			if (dfs(i)) return 1;
		}
	}
	return 0;
}


int main() {
	scanf("%d %d %d", &n, &m, &k);

	skill_sets.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		link[0][i] = 2;
	}

	for (int i = 1; i <= m; i++) {
		link[n + i][LAST_POINT] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int nums;
		skill_sets[i].first = i;
		scanf("%d", &nums);
		for (int j = 0; j < nums; j++) {
			int temp;
			scanf("%d", &temp);
			link[i][n + temp] = 1;
			skill_sets[i].second.push_back(temp);
			for (int q = 1; q < i; q++) {
				auto isAt = find(skill_sets[q].second.begin(), skill_sets[q].second.end(), temp);
				if (skill_sets[q].second.end() != isAt ) {
					skill_sets[q].second.erase(isAt);
				}
			}
		}
	}
	
	sort(skill_sets.begin()+1, skill_sets.end(),cmp);

	for (auto i = skill_sets.begin() + 1; i != skill_sets.end(); i++) {
		int link_num = 1;
		if (k > 0) {
			link_num = 2;
			k--;
		}
		link[0][(*i).first] = link_num;
	}
	int result = 0;

	while (dfs(0)) {
		memset(visited, 0, sizeof(int) * (LAST_POINT + 1));
		result++;
		back(LAST_POINT);
	}
	printf("%d\n", result);

	return 0;
}