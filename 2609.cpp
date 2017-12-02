#include <stdio.h>


int gcd(int a, int b) {
	if (a == 0) return b;

	return gcd(b%a, a);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int result;
	result = gcd(a, b);

	printf("%d\n", result);

	int mul_result = (a*b) / result;

	printf("%d", mul_result);
	return 0;
}