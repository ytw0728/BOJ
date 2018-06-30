#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	a = n / 10;
	b = n % 10;
	int cnt = 0;

	while (1) {
		int tmp = (a + b) % 10;
		a = b;
		b = tmp;
		cnt++;
		if (a * 10 + b == n) break;
	}
	printf("%d\n", cnt);
	return 0;
}