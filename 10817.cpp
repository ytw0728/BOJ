#include <stdio.h>
int main() {
	int n[3];
	scanf("%d %d %d", &n[0], &n[1], &n[2]);

	for (int i = 0; i < 2; i++) {
		for( int j = 0; j< 2; j++){
			if (n[j] < n[j + 1]) {
				int tmp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmp;
			}
		}
	}

	printf("%d", n[1]);
	return 0;
}