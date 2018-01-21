#include <stdio.h>

int main() {

	int t, time;
	scanf("%d %d", &t, &time);

	int cnt = 0;
	while (t--) {
		int tmp;
		scanf("%d", &tmp);
		if (time - tmp >= 0) cnt++;
		time -= tmp;
	}

	printf("%d\n", cnt);
	return 0;
}