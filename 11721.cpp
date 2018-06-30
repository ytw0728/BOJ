#include <stdio.h>
int main() {
	char c;
	int n = 0;
	while ((c = getchar()) != EOF) {
		printf("%c", c);
		if (n == 9) {
			printf("\n");
			n = 0;
		}
		else n++;
	}
	return 0;
}