#include <stdio.h>
#define PI 3.14159265358979323846

int main() {
	int r;
	scanf("%d", &r);
	printf("%.6f\n", r*r*PI);
	printf("%.6f", r*(2.0*r));
	return 0;
}