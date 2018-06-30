#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int arr[105];
int dp[10005];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i< n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = 1;
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		for( int j = 0; j + arr[i] <= k;j++){
			dp[j + arr[i]] += dp[j];
		}
	}

	printf("%d\n", dp[k]);

	return 0;
}