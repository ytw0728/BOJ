#include <stdio.h>

int main() {
	while (1) {
		int n, p;

		scanf("%d", &n);
		if (n == 0) return 0;
		scanf("%d", &p);

		int arr[4] = { 0, };

		int firstP = p;
		if (p > n / 2) firstP = n - p + 1;


		if (firstP % 2) {
			arr[0] = firstP;
			arr[1] = firstP + 1;
		}
		else {
			arr[0] = firstP - 1;
			arr[1] = firstP;
		}

		firstP = arr[0];

		int lastP = n - arr[0] + 1;
		arr[2] = lastP - 1;
		arr[3] = lastP;

		for (int i = 0; i < 4; i++) {
			if (arr[i] == p) continue;
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}