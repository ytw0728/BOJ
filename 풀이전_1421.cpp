// ³ª¹«²Û ÀÌ´Ù¼Ø
#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int numberOfWood, cutFee, price;

	scanf("%d %d %d", &numberOfWood, &cutFee, &price);
	int *woods = (int*)malloc(sizeof(int)*numberOfWood);
	int longest = 0;;
	for (int i = 0; i < numberOfWood; i++) {
		scanf("%d", woods + i);
		if (longest < woods[i]) longest = woods[i];
	}

	int tempSum = 0 , sumOfPrice = 0;
	int numberOfPiece = 0, priceEach, moreFee;
	for (int length = longest; length > 0; length--) {
		tempSum = 0;
		for (int j = 0; j < numberOfWood; j++) {
			numberOfPiece = woods[j] / length;
			(woods[j] % length) ? moreFee = 1 : moreFee = 0;

			priceEach = numberOfPiece * length * price - ((numberOfPiece - 1) + moreFee) * cutFee;
			if (priceEach > 0) tempSum += priceEach;
		}

		if (sumOfPrice < tempSum) sumOfPrice = tempSum;
	}

	printf("%d\n", sumOfPrice);
}