#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int t = n;
	int diff = -1;
	for (int i = 1; i <= 2 * n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < t) printf(" ");
			else printf("*");
		}
		printf("\n");
		t += diff;
		if (t == 1) diff = 1;
	}
	return 0;
}