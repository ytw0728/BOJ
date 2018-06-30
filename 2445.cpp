#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			if (j <= i || 2 * n - i < j) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (int i = n-1; i > 0; i--) {
		for (int j = 1; j <= 2 * n; j++) {
			if (j <= i || 2 * n - i < j) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}