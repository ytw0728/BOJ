#include <cstdio>

using namespace std;

int n, k;
long long dp[205][205]; // a °ª b ¹ø

int go(int a, int b) {
	if (a < 0 || b < 0) return 0;
	if (a == 0 && b == 0) return 1;

	long long &ret = dp[a][b];
	if (ret) return (int)(ret%1000000000);
	
	for (int i = 0;  a - i >= 0; i++) {
		ret += go( a - i, b - 1)%1000000000;
	}


	return (int)(ret%1000000000);
}

int main() {	
	scanf("%d %d", &n, &k);

	int result = go(n,k);
	
	printf("%d\n", result);

	return 0;
}