#include <cstdio>

using namespace std;

int comb[35][35];

int main() {
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);
	
	comb[0][0] = 1;
	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) comb[i][j] = 1;
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
	}

	r--;
	c--;

	long long sum = 0;
	for (int i = r; i < r + w; i++) {
		for (int j = c; j <= (i-r) + c; j++){
			sum += comb[i][j];
		}
	}

	printf("%lld\n", sum);

	return 0;
}