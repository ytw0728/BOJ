#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int max = -1;
	if (n == 0) {
		printf("0");
		return 0;
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		max = max < tmp ? tmp : max;
	}
	double result = sum;
	result *= 100.00 / (max * n);

	printf("%.2lf", result);
	return 0;
}