#include <stdio.h>
#include <algorithm>

using namespace std;

long long arr[55];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	if (n == 1) printf("%lld", arr[0] * arr[0]);
	else {
		printf("%lld", arr[0] * arr[n - 1]);
	}
	return 0;
}