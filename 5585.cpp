#include <stdio.h>

int main() {
	int v;
	scanf("%d", &v);
	v = 1000 - v;
	int cnt = 0;

	while (v >= 500) {
		v -= 500;
		cnt++;
	}
	while (v >= 100) {
		v -= 100;
		cnt++;
	}
	while (v >= 50) {
		v -= 50;
		cnt++;
	}
	while (v >= 10) {
		v -= 10;
		cnt++;
	}
	while (v >= 5) {
		v -= 5;
		cnt++;
	}
	while (v >= 1) {
		v -= 1;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}