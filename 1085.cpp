#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int dis;
	if (x < w - x) dis = x;
	else dis = w - x;

	dis = min(dis, y);
	dis = min(dis, h - y);

	printf("%d\n", dis);
	return 0;
}