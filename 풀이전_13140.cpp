#include <algorithm>
#pragma warning (disable:4996)

using namespace std;
int main() {
	int arr[10], n;
	scanf("%d", &n);
	
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
		
	do{
		if (arr[0] && arr[4]) {
			int hello = arr[0] * 1e4 + arr[1] * 1e3 + arr[2] * 1e2 + arr[2] * 10 + arr[3];
			int world = arr[4] * 1e4 + arr[3] * 1e3 + arr[5] * 1e2 + arr[2] * 10 + arr[6];
			if (hello + world == n) {
				printf("%7d\n+%6d\n-------\n%7d", hello, world, n);
				return 0;
			}
		}
	}while (next_permutation(arr, arr + 10));

	printf("No Answer");
	return 0;
}
