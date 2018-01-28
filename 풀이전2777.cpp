#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int index = 0;
int* primeNumber = NULL;
int* getPrime(int target) {
	index = 0;
	int primeTemp, targetTemp = target;
	if (primeNumber != NULL) {
		free(primeNumber);
		primeNumber = NULL;
	}
	primeNumber = (int*)malloc(sizeof(int)*(target/2 +1) );
	while (targetTemp > 1) {
		for (primeTemp = 2; targetTemp%primeTemp; primeTemp++);
		if (target != primeTemp && primeTemp < 10) {
			primeNumber[index++] = primeTemp;
			targetTemp /= primeTemp;
		}
		else {
			free(primeNumber);
			primeNumber = NULL; index = 0;
			break;
		}
	}
	return primeNumber;
}

int contractionCount( int* primeNumber, int n ) {
	int contractionIndex = 0;
	int sum = primeNumber[0];
	int last= 0, i;
	if (index != 2) {
		for (i = 1; i < index; i++) {
			if (sum * primeNumber[i] < 10 && sum * primeNumber[i] != n ) sum *= primeNumber[i];
			else {
				sum = primeNumber[i];
				contractionIndex++;
				last = i;
			}
		}
		if (last != i) contractionIndex += (i - last);
	}
	else {				// exception 한자리 숫자로 이뤄지는 제곱수   xxxxx => 그냥 다 index 2면 2가 됨. 두 곱은 n 이기때문
		contractionIndex = 2;
	}
	if (contractionIndex) return contractionIndex;
	else return index;
}
int main(){
	int* temp;
	int testCase; scanf("%d", &testCase);
	int* n = (int*)malloc(sizeof(int)*testCase);
	for (int i = 0; i < testCase; i++) scanf("%d", &n[i]);
	for (int i = 0; i < testCase; i++) {
		temp = getPrime(n[i]);
		if (temp) {
			printf("%d\n", contractionCount(temp, n[i]));
		}
		else printf("-1\n");
	}
	free(n);
	n = NULL;
	return 0;
}

// 1. 소인수 분해 2. 10 이상의 소인수 발생 -> -1 
// 3. 소인수 최대 축약 => ex) 12 = 2 * 2 * 3 = 4 * 3 -> 34 , 36 = 2*2*3*3 = 4 * 9 = 