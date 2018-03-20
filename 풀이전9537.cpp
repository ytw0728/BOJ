// Àß»ý±ä gcd
#include <cstdio>
#include <vector>

using namespace std;

long long arr[100005];
long long gcdTable[100005];

long long gcd(long long a, long long b) {
	long long tmp = a;
	while (b != 0) {
		a = b;
		b = tmp%b;
		tmp = a;
	}
	return a;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);
		long long max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			gcdTable[i] = arr[i];
			max = max < arr[i] ? arr[i] : max;
		}
		
		for (int len = 2; len <= n; len++) {
			long long maxGCD = 0;
			for (int i = 0; i <= n - len; i++) {
				gcdTable[i] = gcd(gcdTable[i], arr[i + len - 1]);
				maxGCD = maxGCD < gcdTable[i] ? gcdTable[i] : maxGCD;
			}
			max = max < maxGCD * len ? maxGCD * len : max;
		}
		
		printf("%lld\n", max);
		

	}
	return 0;
}