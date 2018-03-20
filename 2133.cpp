#include <cstdio>

using namespace std;

long long dp[35][35]; // ³²Àº Ä­ / »¬Ä­
int n;

long long go(int s, int m){
	if (s < 0) return 0;
	if (s == 0) {
		if (m == 2) return 3;
		else return 2;
	}
	
	long long &ret = dp[s][m];

	if (ret) return ret;

	long long sum = 0;
	for (int i = 2; i <= s; i += 2) {
		if (i == 2) {
			sum += go(s - i, i);
		}
		else {
			sum += go(s - i, i);
		}
	}
	if (m == 0) ret = 1;
	else if (m > 2) ret = 2;
	else ret = 3;

	ret *= sum;
	return ret;
}
int main() {
	scanf("%d", &n);
	long long result = 0;
	if (n % 2 == 0 ) result = go(n, 0);
	printf("%lld", result);
	return 0;
}