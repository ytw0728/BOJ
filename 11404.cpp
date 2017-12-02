#include <stdio.h>
#include <vector>
#define INF 99999999

using namespace std;

int n, m;
int dist[101][101];

int main() {
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = dist[a][b] > c? c: dist[a][b];
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] >= INF) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}