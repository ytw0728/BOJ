#include <stdio.h>
#include <algorithm>
#include <limits.h>
#define MAX_VAL 1000000

using namespace std;

int n;
int dp1[3][3]; // 최대
int dp2[3][3]; // 최소

int main() {
	scanf("%d", &n);
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);

		dp1[1][0] = max(dp1[0][0], dp1[0][1]) + a;
		dp1[1][1] = max(max(dp1[0][0], dp1[0][1]), dp1[0][2]) + b;
		dp1[1][2] = max(dp1[0][1], dp1[0][2]) + c;

		dp2[1][0] = min(dp2[0][0], dp2[0][1]) + a;
		dp2[1][1] = min(min(dp2[0][0], dp2[0][1]), dp2[0][2]) + b;
		dp2[1][2] = min(dp2[0][1], dp2[0][2]) + c;


		dp1[0][0] = dp1[1][0];
		dp1[0][1] = dp1[1][1];
		dp1[0][2] = dp1[1][2];

		dp2[0][0] = dp2[1][0];
		dp2[0][1] = dp2[1][1];
		dp2[0][2] = dp2[1][2];
	}
	
	
	int result1 = max(max(dp1[0][0], dp1[0][1]), dp1[0][2]);
	int result2 = min(min(dp2[0][0], dp2[0][1]), dp2[0][2]);

	printf("%d %d",result1, result2);

	return 0;
}