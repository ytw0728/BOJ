#include <stdio.h>
int main() {
	int r, e, c;

	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &r, &e, &c);

		int adver = e - c;
		if (r > adver) printf("do not advertise\n");
		else if (r < adver) printf("advertise\n");
		else printf("does not matter\n");
	}
	return 0;
}