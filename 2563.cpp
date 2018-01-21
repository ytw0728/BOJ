#include <stdio.h>

int arr[101][101];

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);

		int until = x + 10;
		for (int i = x+1; i <= until; i++) {
			for (int j = y + 10; j >= y+1; j--) {
				arr[i][j] = 1;
			}
		}
	}

	int S = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j]) S++;
		}
	}

	printf("%d\n", S);
	return 0;
}