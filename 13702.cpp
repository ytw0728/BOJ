#include <cstdio>
#include <algorithm>
using namespace std;
int arr[10005];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	int right = arr[n - 1];
	int left = 0;
	int mid = 0;

	while (left <= right) {
		int idx = 0;
		int now = arr[idx++];

		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (now - mid < 0 && idx < n) now = arr[idx++];
			else if( now - mid < 0 ) break;
			now -= mid;
			cnt++;
		}

		if (cnt > k) left = mid;
		else right = mid - 1;
	}

	printf("%d\n", mid);

	return 0;
}