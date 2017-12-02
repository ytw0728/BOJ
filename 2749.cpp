#include <stdio.h>
#define DIV 1000000

int cycle = (DIV / 10) * 15;

int main() {
	long long n;
	scanf("%lld", &n);

	int x = 0;
	int y = 1;
	int result;
	if (n == 0) printf("0");
	else if (n == 1) printf("1");
	else {
		for (int i = 2; i <= n%cycle; i++) {
			result = x + y;
			result %= DIV;
			x = y;
			y = result;
		}
		printf("%d", result);
	}

	return 0;
}