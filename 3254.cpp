#include <stdio.h>


int arr[7][8];

int find(int x, int y, int v) {
	int cnt = 0;

	int xStart = x - 3;
	if (xStart < 1) xStart = 1;
	int xEnd = x + 3;
	if (xEnd > 6) xEnd = 6;
	for (int i = xStart; i <= xEnd; i++) {
		if (arr[i][y] == v) cnt++;
		else cnt = 0;


		if (cnt == 4) return 1;
	}

	int yStart = y - 3;
	if (yStart < 1) yStart = 1;
	cnt = 0;
	for (int i = yStart; i <= y; i++) {
		if (arr[x][i] == v) cnt++;
		else cnt = 0;

		if (cnt == 4) return 1;
	}
	

	

	int leftXStart = x;
	int leftYStart = y;
	int low = 3;
	while ( low-- && leftXStart > 1 && leftYStart > 1) {
		leftXStart--;
		leftYStart--;
	}
	
	int high = 8;
	cnt = 0;
	while (high-- && leftXStart <= 6 && leftYStart <= 7) {
		if (arr[leftXStart++][leftYStart++] == v) cnt++;
		else cnt = 0;

		if (cnt == 4) return 1;
	}

	int rightXStart = x;
	int rightYStart = y;
	low = 3;
	while ( low-- && rightXStart > 1 && rightYStart < 7) {
		rightXStart--;
		rightYStart++;
	}

	high = 8;
	while (high-- && rightXStart <= 6 && rightYStart >= 1) {
		if (arr[rightXStart++][rightYStart--] == v) cnt++;
		else cnt = 0;
		if (cnt == 4) return 1;
	}

	return 0;
}

int main() {
	int n = 21;
	int cnt = 0;
	int done = 0;
	while (n--) {
		int S, J;
		scanf("%d %d", &S, &J);
		if (!done) {
			int Sy = 1;
			while (arr[S][Sy] != 0) Sy++;
			arr[S][Sy] = -1;
			int Jy = 1;
			while (arr[J][Jy] != 0) Jy++;
			arr[J][Jy] = 1;

			cnt++;
			int sR = 0;
			int jR = 0;
			if (cnt >= 4) {
				sR = find(S, Sy, -1);
				jR = find(J, Jy, 1);
			}

			if (sR) {
				printf("sk %d", cnt);
				return 0;
			}
			if (jR) {
				printf("ji %d", cnt);
				return 0;
			}
			
		}
	}

	printf("ss");
	return 0;
}