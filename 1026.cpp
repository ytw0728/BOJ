#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int arr1[55];
int arr2[55];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr2[i]);
	}
	

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n, greater<int>());

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr1[i] * arr2[i];
	}

	printf("%lld", sum);
	
	return 0;
}