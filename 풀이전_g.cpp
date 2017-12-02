#include <stdio.h>

int n;
int yes = 0;
int trail[101][101];
int trail_temp[101][101];

void go(int p) {

	for (int i = 0; i < n; i++) {
		if ( i != p && trail_temp[p][i] ) {
			trail_temp[p][i]--;
			trail_temp[i][p]--;
			go(i);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int pack;
		scanf("%d", &pack);
		for (int q = 0; q <= n; q++) {
			for (int p = 0; p <= n; p++) {
				trail[q][p] = 0;
			}
		}
		for (int j = 1; j <= pack; j++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			trail[x][y] = trail[y][x] = z;
		}

		yes = 0; 
		for (int j = 0;!yes && j < n; j++) {

			for (int q = 0; q <= n; q++) {
				for (int p = 0; p <= n; p++) {
					trail_temp[q][p] = trail[q][p];
				}
			}

			go(j);

			yes = 1;
			for (int q = 0; q <= n; q++) {
				for (int p = 0; p <= n; p++) {
					if (trail_temp[q][p] != 0) {
						yes = 0;
						break;
					}
				}
				if (!yes) break;
			}
		}

		if (yes) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}