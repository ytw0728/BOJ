#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[500001];

int main() {
	int n; scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + n + 1);

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += abs(i - arr[i]);
	}
	printf("%lld\n", sum);

	return 0;
}