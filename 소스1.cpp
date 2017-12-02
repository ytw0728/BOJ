#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int map[1501][1501];
int n;
int t;
int go(int s) {

}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int min_time;
	t = 1;
	min_time = go(1);

	t = 0;
	min_time = min(min_time, go(n));

	printf("%d", min_time);
	return 0;
}