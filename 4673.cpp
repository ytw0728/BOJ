#include <stdio.h>
int chk[10005];
int main() {
	for (int i = 1; i <= 10000; i++) {
		int tmp = i;
		long long sum = tmp;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if( sum <= 10000 ) chk[sum] = 1;
	}

	for (int i = 1; i <= 10000; i++) {
		if (!chk[i]) printf("%d\n",i);
	}
	return 0;
}