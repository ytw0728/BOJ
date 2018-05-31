#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1005];
int dp[1005];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				sum = max(sum, dp[j]);
			}
		}
		dp[i] = sum + arr[i];
	}

	int maximum = 0;
	for (int i = 0; i < n; i++) {
		maximum = maximum < dp[i] ? dp[i] : maximum;
	}

	printf("%d\n", maximum);
	return 0;
}