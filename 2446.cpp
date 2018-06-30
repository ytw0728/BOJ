#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - i - 1; j++) {
			if (j < i) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 1; j <= 2 * n - i; j++) {
			if (j < i) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}