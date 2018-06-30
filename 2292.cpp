#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 1;
	int k = 6;
	n -= 1;
	while(n > 0) {
		n -= k;
		k += 6;
		cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}