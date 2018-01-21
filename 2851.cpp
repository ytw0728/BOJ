#include <stdio.h>
#include <math.h>

int arr[10];

int main() {
	for( int i = 0 ; i < 10 ;i++){
		int t;
		scanf("%d", &t);
		arr[i] = t;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		if (abs(sum + arr[i] - 100) <= abs(sum - 100)) sum += arr[i];
		else break;
	}

	printf("%d\n", sum);

	return 0;
}