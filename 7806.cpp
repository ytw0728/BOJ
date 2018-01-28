#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	long long n, k;
	while (~scanf("%lld %lld", &n, &k)) {

		long long tmpK = k;
		long long result = 1;

		for (int i = 2; i*i <= k && tmpK >= i; i++) {
			int numK = 0;
			while (tmpK % i == 0) {
				tmpK /= i;
				numK++;
			}

			if (numK) {
				int numN = 0;
				for (int j = i; j <= n; j *= i) {
					numN += n / j;
				}
				result *= pow(i, min(numK, numN));
			}
		}

		if (tmpK > 1 && tmpK <= n)
			result *= tmpK;

		printf("%lld\n", result);

	}
	return 0;
}