#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)
int main(){

	int testCase; scanf("%d", &testCase);
	int* n = (int*)malloc(sizeof(int)* testCase);
	for (int i = 0; i < testCase; i++) scanf("%d", &n[i]);

	for (int i = 0; i < testCase; i++) {
		int index = 9, count = 0, testNumber = 1;
		int temp = n[i];
		while ( temp > 0 && index >= 2) {
			if (temp % index == 0) {
				count++;
				temp /= index;
				testNumber *= index;
			}
			else {
				index--;
			}
		}
		if (testNumber == n[i] ) printf("%d\n", count);
		else printf("-1\n");
	}
	return 0;
}