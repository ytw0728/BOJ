#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		if (tmp / 10 == 0) {
			cnt++;
			continue;
		}
		int diff = tmp/10%10 - tmp%10;
		tmp /= 10;
		int hansoo = 1;
		while (tmp > 0 && hansoo) {
			if (tmp / 10 == 0) break;
			if (tmp / 10 % 10 - tmp % 10 == diff) tmp /= 10;
			else hansoo = 0;
		}
		if (hansoo) cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}