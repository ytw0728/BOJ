#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int tempN = n;
	int five, three; five = three = 0;
	while (tempN - 5 >= 0) {
		five++;
		tempN -= 5;
	}

	while (five >= 0) {
		if ((n - 5 * five) % 3 == 0) {
			three = (n - 5 * five) / 3;
			break;
		}
		five--;
	}
	

	printf("%d", five + three);
	return 0;
}