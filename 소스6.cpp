#include <stdio.h>

int main() {
	int num = 1;
	int income;

	scanf("%d", &num);
	while( num != 0 ){
		if (num <= 1000000) income = num;
		else if (num <= 5000000) income = (num / 10) * 9;
		else income = (num / 10) * 8;
		printf("%d\n", income);
		scanf("%d", &num);
	}
	return 0;
}