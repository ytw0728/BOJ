#include <cstdio>
#include <algorithm>

using namespace std;

int arr[500005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + n);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {

		int tmp;
		scanf("%d", &tmp);

		int left, right, mid;
		left = 0, right = n - 1;

		int done = 0;
		while (!done && left < right) {
			mid = (left + right) / 2;

			if (arr[mid] == tmp) done = 1;
			else if (arr[mid] > tmp) right = mid;
			else if (arr[mid] < tmp) left = mid + 1;
		}

		if (arr[right] == tmp) done = 1;
		printf("%d ", done);
	}
	return 0;
}