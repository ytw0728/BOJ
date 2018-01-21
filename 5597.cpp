#include <stdio.h>

int arr[31];

int main() {
	for (int i = 0; i < 28; i++) {
		int n;
		scanf("%d", &n);

		arr[n] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (!arr[i]) printf("%d\n", i);
	}
	return 0;
}