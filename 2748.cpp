#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long a, b;
	a = 0; b = 1;

	if (n < 2) {
		if (n == 0) printf("%lld", a);
		else if (n == 1) printf("%lld", b);
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		b = a + b;
		a = b - a;
	}
	printf("%lld\n", b);
	


	return 0;
}