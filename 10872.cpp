#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long fact = 1;
	for (int i = 1; i <= n; i++) {
		fact *= i;
	}
	printf("%lld", fact);
	return 0;
}