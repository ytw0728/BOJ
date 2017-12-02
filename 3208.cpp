/*
#include <stdio.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	int cnt = 0;

	while (m > 0 && n > 0) {
		m--; cnt++;
		if (!m) break;
		n--; cnt++;
	}

	printf("%d", cnt - 1);
	return 0;
}
*/
#include <stdio.h>
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d",  ( m <= n )? 2*m-2 : 2*n-1);
	return 0;
}