#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> arr;

int main() {
	int n, budget;
	scanf("%d", &n);
	arr.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	scanf("%d", &budget);
	
	sort(arr.begin(),arr.end());

	if (sum <= budget) {
		printf("%d", arr[n-1] );
		return 0;
	}


	for (int i = 0; i < n; i++) {
		if (arr[i] * (n - i) < budget) {
			budget -= arr[i];
		}
		else {
			printf("%d", budget / (n - i));
			break;
		}
	}
	return 0;
}
