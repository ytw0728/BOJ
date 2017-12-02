#include <stdio.h>

int n;
long long dp[91][2];

long long go(int p, int s) {
	if (p > n) return 0;
	if (p == n) return 1;

	long long& ret = dp[p][s];

	if (ret != 0) return ret;

	if (s < 1) ret += go(p + 1, 1);
	ret += go(p + 1, 0);

	return dp[p][s];
}
int main(){
	scanf("%d",&n);
	long long result = go(1, 1); // n =1 일때, 1을 넣으면 현재 go 함수에 의해서는 dp에 변화가 일어나지 않기 때문에 result로 return 값을 받아야함. 혹은 go 함수에서 p==n일때 dp[p][cnt] = 1 따위의 작업을 수행해줘야 할 것임.
	printf("%lld",result);
	return 0;
}