#include <stdio.h>
#include <algorithm>

using namespace std; 

int dy[501][501]; /// row , column
int map[501][501];

int row;
int go( int i, int s) {
	if (i > row) return 0;
	if (i == row) return map[i][s];

	int max_width = 2*(row-i) +1;
	int& ret = dy[i][s];

	if (ret != 0) return ret;
	int temp = 0;
	
	temp = max( go(i + 1, s), go(i + 1, s + 1));

	ret += temp + map[i][s];
	return ret;
}

int main() {
	scanf("%d", &row);

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int result = go(1,1);
	printf("%d", result);

	return 0;
}