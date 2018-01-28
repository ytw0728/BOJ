#include <cstdio>
#include <math.h>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	long double left = (c - b) / (double)a, right = (c + b) / (double)a, mid;

	int cycle = 50000;
	
	while (left < right && cycle--) {
		mid = (left + right) / 2;

		if (mid >(c - (b*(long double)sin(mid))) / a) right = mid;
		else if (mid < (c - (b*(long double)sin(mid))) / a) left = mid + 0.00000000000000000001;
	}

	printf("%.19Lf", mid + 0.00000000000000000005);
	return 0;
}