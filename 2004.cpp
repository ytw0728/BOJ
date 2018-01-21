#include <stdio.h>
#include <map>
#include <functional>
#include <math.h>

using namespace std;

int main() {
	
	int n, m, NM;
	scanf("%d %d", &n, &m);
	NM = n - m;

	int tCnt = 0, fCnt = 0;

	for (long long i = 2; i <= n; i *= 2) {
		tCnt += n / i;
	}

	for (long long i = 5; i <= n; i *= 5) {
		fCnt += n / i;
	}


	for (long long i = 2; i <= m; i *= 2) {
		tCnt -= m / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		fCnt -= m / i;
	}

	for (long long i = 2; i <= NM; i *= 2) {
		tCnt -= NM / i;
	}
	for (long long i = 5; i <= NM; i *= 5) {
		fCnt -= NM / i;
	}

	printf("%d\n", tCnt > fCnt ? fCnt : tCnt);
	
	return 0;
}