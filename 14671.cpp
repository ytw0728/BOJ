#include <stdio.h>

int arr[1005][1005];

int main() {
	int mX, nY, t;

	scanf("%d %d %d", &mX, &nY, &t);

	int a, b;
	a = b = -1;
	int tmpT = t;
	while (tmpT--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (a == -1) {
			a = x;
			b = y;
		}
		arr[x][y] = 1;
	}

	if (mX * nY == t) {
		printf("YES\n");
		return 0;
	}
	
	// 대각선 모양
	int diag = 0;
	for (int i = ((a % 2) ? 2 : 1); !diag && i <= mX; i += 2){
		int j = b % 2;
		if (i % 2 != a % 2) {
			j++;
		}
		for (j; !diag && j <= nY; j += 2) {
			if ( arr[i][j] && i != a && j != b ) diag = 1;
		}
	}

	// 가로
	int horizontal = 0;
	int j;
	if (b % 2) j = 2;
	else j = 1; 

	int k;
	k = a % 2;
	if (k == 0) k = 2;

	for (; !horizontal && j <= nY; j += 2 ) {
		for (int i = k; !horizontal && i <= mX; i += 2) {
			if (arr[j][i]) horizontal = 1;
		}
	}


	// 세로
	int vertical = 0;
	j = 0;
	j = b % 2;
	if (j == 0) j = 2;

	k = 0;
	if (a % 2) k = 2;
	else k = 1;

	for (; !vertical && j <= nY; j += 2) {
		for (int i = k; !vertical&& i <= mX; i += 2) {
			if (arr[j][i]) vertical = 1;
		}
	}

	if (vertical && horizontal && diag) printf("YES\n");
	else printf("NO\n");
	


	return 0;
}