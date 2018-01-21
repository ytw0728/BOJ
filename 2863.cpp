#include <stdio.h>

float arr[2][2];

void rotate() {
	float a, b, c, d;
	a = arr[0][0];
	b = arr[0][1];
	c = arr[1][1];
	d = arr[1][0];

	arr[0][1] = a;
	arr[1][1] = b;
	arr[1][0] = c;
	arr[0][0] = d;
}


int main() {

	for(int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++) {
			scanf("%f", &arr[i][j]);
		}
	}
	
	
	float max = -1;
	int idx = 0;



	for (int i = 0; i < 4; i++) {
		float tmp = arr[0][0] / arr[1][0] + arr[0][1] / arr[1][1];
		if (max < tmp) {
			max = tmp;
			idx = i;
		}
		rotate();
	}

	printf("%d", idx);
	
	
	return 0;
}