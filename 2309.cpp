#include <cstdio>
#include <algorithm>

using namespace std;

int arr[9];
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += arr[i];
		}
		if (sum == 100) break;
	} while (next_permutation(arr, arr+9));

	sort(arr, arr + 7);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}