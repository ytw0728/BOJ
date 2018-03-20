#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int arr[3], n;

	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &n);

	
	int unt0 = n / arr[0];
	int unt1 = n / arr[1];
	int unt2 = n / arr[2];
	bool result = false;
	for (int i = 0; !result && i <= unt0; i++) {
		for (int j = 0; !result && j <= unt1; j++) {
			for (int k = 0; !result && k <= unt2; k++) {
				int now = arr[0] * i + arr[1] * j + arr[2] * k;
				
				if (now == n) result = true;
			}
		}
	}

	
	printf("%d", result);
	return 0;
}