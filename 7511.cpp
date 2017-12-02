// 여러 관계에 따라 경로가 있는지 없는지를 알아내야 함
#pragma warning (disable: 4996)
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<vector<set<int>>> setting;
vector<vector<pair<int, int>>> f;
int main() {
	int testCase;
	scanf("%d", &testCase);

	setting.resize(testCase);
	f.resize(testCase);
	int num;
	int a, b;
	for (int i = 0; i < testCase; i++) {
		scanf("%d", &num);
		setting[i].resize(num);
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d %d", &a, &b);
			setting[i][a].insert(b);
			setting[i][b].insert(a);
		}

		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d %d", &a, &b);
			if (a < b) {
				int temp = a;
				a = b;
				b = temp;
			}
			f[i].push_back(make_pair(a, b));
		}
	}


	for (int i = 0; i < testCase; i++) {
		printf("Scenario %d:\n", i + 1);
		auto v = f[i].begin();
		for (v; v != f[i].end(); v++){
			if (setting[i][(*v).first].find((*v).second) != setting[i][(*v).first].end()) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}