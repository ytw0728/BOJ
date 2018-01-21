#include <stdio.h>
#include <math.h>


int main() {

	int n;
	scanf("%d", &n);

	while (n--) {
		int x1, y1, r1, x2, y2, r2;

		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double distance = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );
			
		if (r1 < r2) {
			int tmpX, tmpY, tmpR;
			tmpX = x1;
			tmpY = y1;
			tmpR = r1;
			x1 = x2;
			y1 = y2;
			r1 = r2;
			x2 = tmpX;
			y2 = tmpY;
			r2 = tmpR;
		}

		if (distance == 0) {
			if (r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else if (distance < r1) {
			if (r1 - r2 < distance) printf("2\n");
			else if (r1 - r2 > distance) printf("0\n");
			else printf("1\n");
		}
		else {
			if (r1 + r2 > distance) printf("2\n");
			else if (r1 + r2 < distance) printf("0\n");
			else printf("1\n");
		}
	}
	return 0;
}