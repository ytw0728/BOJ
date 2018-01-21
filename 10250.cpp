#include <stdio.h>


int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int	h, w, n;
		scanf("%d %d %d", &h, &w, &n);

		int i, j;
		for (i = 1; i <= w ; i++) {
			for (j = 1; j <= h ; j++) {
				n--;
				if (n <= 0) break;
			}
			if (n <= 0) break;
		}

		printf("%d%02d\n", j, i);
	}

	return 0;
}