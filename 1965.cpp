#include <cstdio>

using namespace std;

int arr[1005];
int dp[1005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = 1;
	int max = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i] ) {
				dp[i] = dp[j] + 1;
			}
		}
		max = max < dp[i] ? dp[i] : max;
	}
	

	printf("%d\n", max);
	return 0;
}