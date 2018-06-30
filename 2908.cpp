#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	int revA, revB;
	revA = revB = 0;

	for (int i = 0; i < 3; i++) {
		revA += a % 10; revB += b % 10;
		revA *= 10; revB *= 10;
		a /= 10; b /= 10;
	}
	revA /= 10; revB /= 10;
	
	printf("%d\n", revA > revB ? revA : revB);
	
	return 0;
}