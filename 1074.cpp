#include <stdio.h>
#include <math.h>

int n, r, c;

int find(int n, int x, int y){
	if (n == 1) {
		if (x + y == 0) return 0;
		else if (x + y == 2) return 3;
		else if (x == 1) return 1;
		else return 2;
	}

	int power = pow(2, n - 1);
	if ( x <= power- 1 && y <= power- 1 ) return find( n-1, x,y);
	if (x > power - 1 && y <= power - 1 ) return find(n - 1, x - power , y) + pow(power,2);
	if (x <= power - 1 && y > power - 1) return find(n - 1, x, y - power) + pow(power, 2) * 2;
	if (x > power - 1 && y > power - 1) return find(n - 1, x - power , y - power) + pow(power, 2) * 3;
}
int main() {
	scanf("%d %d %d", &n, &r, &c);

	int result = find(n, c, r);

	printf("%d", result);
	return 0;
}