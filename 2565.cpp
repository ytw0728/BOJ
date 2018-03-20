#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair< int, int> > arr;
int dp[105];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end());

	dp[0] = 1;
	int max = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}

			max = dp[i] > max ? dp[i] : max;
		}
	}

	printf("%d\n", n - max);
	return 0;
}