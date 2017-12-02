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
	long long result = go(1, 1); // n =1 �϶�, 1�� ������ ���� go �Լ��� ���ؼ��� dp�� ��ȭ�� �Ͼ�� �ʱ� ������ result�� return ���� �޾ƾ���. Ȥ�� go �Լ����� p==n�϶� dp[p][cnt] = 1 ������ �۾��� ��������� �� ����.
	printf("%lld",result);
	return 0;
}