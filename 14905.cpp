#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
bool primeChk[100000002];

void init() {
	long long i;
	for (i = 2; i*i <= 100000000; i++) {
		if (!primeChk[i]) {
			for (long long j = i*i; j <= 100000000; j += i) {
				primeChk[j] = 1;
			}
		}
	}
}

int main() {
	init();
	int num;
	while (scanf("%d", &num) != EOF) {
		int a, b, c, d;
		a = b = 2;
		if (num > 7) {
			if (num % 2) {
				num -= 5;
				b = 3;
			}
			else {
				num -= 4;
			}
			int done = 0;
			for (c = 2; c <= 100000000 && c < num && !done; c++) {
				if (!primeChk[c] && !primeChk[num - c]) done = 1;
			}
			c--;
			d = num - c;
			if (done) printf("%d %d %d %d\n", a, b, c, d);
			else printf("Impossible.\n");
		}
		else printf("Impossible.\n");
	}

	return 0;
}