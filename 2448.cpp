#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool isStar[10000][10000];

void star(int x1, int y1, int x2, int y2, int n) {

	if (n == 3) {
		for (int i = x1; i <= x2; i++) {
			isStar[i][y1] = 1;
		}
		isStar[x1 + 1][y1 + 1] = isStar[x1 + 3][y1 + 1] = isStar[x1 + 2][y1 + 2] = 1;
		return;
	}
	star( (x1 + n/2 ) , (y1 + n/2), (x1 + n + 1), (y1+n-1), (n/2)  ); // top
	star( (x1), (y1), (x1+n-2), (y1+n/2-1), (n/2)  ); //left
	star( (x1 + n), (y1), (x1 + 2*n - 2), (y1 + n/2 - 1) , (n / 2) ); // right
}
int main() {
	int n;
	scanf("%d", &n);

	star(1, 1, 2*n-1, n, n);

	string result;

	for (int i = n; i >= 1; i--) {
		result.clear();
		for (int j = 2*n-1; j >= 1; j--) {
			if (isStar[j][i]) result += '*';
			else result += ' ';
		}
		cout << result << endl;
	}

	return 0;
}