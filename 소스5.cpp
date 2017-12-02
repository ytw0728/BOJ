#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int dp[8];

int go(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;

	int& ret = dp[n];
	if (ret != 0) return ret;
	ret = n*go(n - 1);
	return ret;
}
int main() {

	int t;
	int cnt = 0;
	int rev_cnt = 362880;

	scanf("%d", &t);

	string temp;
	int nums[9] = { 0,1,2,3,4,5,6,7,8 };

	for (int i = 0; i < t; i++) {
		cin >> temp;
		int sum = 0;
		for (int j = 0; j < 9; j++) nums[j] = j;
		for (int j = 0; j < 9; j++) {
			for (int k = temp[j] - 'a'+1; k < 9; k++) {
				nums[k]--;
			}
			sum += go(8-j) *( nums[ temp[j] -'a' ] );
		}
		
		printf("%d\n", sum+1);
	}

	return 0;
}