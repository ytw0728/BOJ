#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);

	int num = 1;
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		num *= i;
		while (num % 10 == 0) {
			cnt++;
			num /= 10;
		}
		num %= 10000;
	}


	printf("%d\n", cnt);
	return 0;
}