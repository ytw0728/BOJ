#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int arr[50005];

int main() {
	int d, n, m;
	scanf("%d %d %d", &d, &n, &m);
	
	if (n == 0) {
		printf("%d\n", d);
		return 0;
	}
	arr[0] = 0;
	arr[1] = d;
	n+= 2;


	for (int i = 2; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	int minimum = 987654321;
	int maximum = arr[n - 1] - arr[0];
	for (int i = 0; i < n - 1; i++) {
		minimum = minimum > arr[i + 1] - arr[i] ? arr[i + 1] - arr[i] : minimum;
	}
	
	int left = minimum;
	int right = maximum;
	int mid, cnt;

	vector<int> answers;
	while ( left < right) {
		mid = (left + right) / 2;
		cnt = 0;
		int idxPlus = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1 - idxPlus] < mid) {
				idxPlus++;
				cnt++;
			}
			else idxPlus = 0;
		}

		if (cnt > m) right = mid;
		else {
			answers.push_back(mid);
			left = mid + 1;
		}
		
	}

	sort(answers.begin(), answers.end());

	printf("%d\n", answers.back());

	return 0;
}