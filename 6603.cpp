#pragma warning (disable: 4996)
#include <stdio.h>
int numbers[6][13];
int testCases[6];
int print(int index) {
	int a, b, c, d, e, f;

	for (a = 0 ; a < testCases[index] - 5; a++) {
		for (b = a+1; b < testCases[index] - 4; b++) {
			for (c = b+1; c < testCases[index] - 3; c++) {
				for (d = c+1; d < testCases[index] - 2; d++) {
					for (e = d+1; e < testCases[index] - 1; e++) {
						for (f = e+1; f < testCases[index]; f++) {
							printf("%d ", numbers[index][a]);
							printf("%d ", numbers[index][b]);
							printf("%d ", numbers[index][c]);
							printf("%d ", numbers[index][d]);
							printf("%d ", numbers[index][e]);
							printf("%d", numbers[index][f]);
							printf("\n");
						}
					}
				}
			}
		}
	}

	return 0;


}

int main() {

	int testCase = 1;
	int index = 0;

	while (testCase) {
		scanf("%d", &testCase);
		testCases[index] = testCase;
		for (int i = 0; i < testCase; i++) {
			int temp;
			scanf("%d", &temp);
			numbers[index][i] = temp;
		}
		index++;
	}

	for (int i = 0; i < index; i++) {
		print(i);
		printf("\n");
	}


	return 0;
}