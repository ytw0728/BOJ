#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector< pair<int, int > > arr; // °ª , Ä®·Î¸®

int dp[10005]; // Ä®·Î¸®
bool chk[10005];

int main() {
	while (1) {
		memset(dp, 0x0, sizeof(dp) );
		memset(chk, 0x0, sizeof(chk));
		int n; double m; 
		scanf("%d %lf", &n, &m);
		int mTmp = (int)(m * 100 + 0.5);
		if (n == 0) break;

		arr.clear();
		for (int i = 0; i < n; i++) {
			int c; double p;
			scanf("%d %lf", &c, &p);
			int pTmp = (int)(p * 100.0 + 0.5);
			arr.push_back(make_pair(pTmp, c));
		}

		sort(arr.begin(), arr.end());
		/*
		queue<int> q;
		q.push(0);
		int maximum = 0;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (auto i = arr.begin(); i != arr.end(); i++) {
				int tmp = now + (*i).first;
				if (tmp > mTmp) break;
				if (!chk[tmp]) {
					q.push(tmp);
					chk[tmp] = 1;
				}
				dp[tmp] = max(dp[tmp], dp[now] + (*i).second);
				maximum = maximum < dp[tmp] ? dp[tmp] : maximum;
			}
			memset(chk, 0x0, sizeof(chk));
		}
		*/
		
		int minimumCost = arr[0].first;
		int maximum = 0;
		for (int i = minimumCost; i <= mTmp; i++) {
			for (auto j = arr.begin(); j != arr.end(); j++) {
				if (i - (*j).first < 0) break;
				dp[i] = max(dp[i], dp[i - (*j).first] + (*j).second);
				maximum = maximum < dp[i] ? dp[i] : maximum;
			}
		}
		
		printf("%d\n", maximum);
	}


	return 0;
}

