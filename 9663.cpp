#include <stdio.h>
#include <deque>
using namespace std;

int main() {
	int n;
	deque<int> result;
	deque<int> temp;
	scanf("%d", &n);

	int chk[15][15];
	int x, y;
	int cnt = 0;
	bool done = 0;
	for (int circle = 0; circle < n; circle++) {

		for (x = 0; x < n; x++) {
			for (y = 0; y < n; y++) {
				if (y == circle || (x - y) == (0 - circle)) chk[x][y] = 1;
				else chk[x][y] = 0;
			}
		}

		for (int row = 1; row < n; row++) {
			for (int column = 0; column < n; column++) {
				if (!chk[row][column]) {
					cnt++;
					for (x = 0; x < n; x++) {
						for (y = 0; y < n; y++) {
							if (column == y || (row - column) == (x - y) || (row-column) == -(x-y) ) chk[x][y] = 1;
						}
					}
					break;
				}
			}
		}
	}


	printf("%d", cnt);
	return 0;
}