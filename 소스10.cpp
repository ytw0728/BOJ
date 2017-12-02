#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int gra[50001];

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		float sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &gra[j]);
			sum += gra[j];
		}
		float avg = sum / n;
		sort(gra, gra + n);

		int a, b;
		a = gra[0];
		b = gra[n - 1];

		float avg2 = (a + b) / 2.0;

		if (abs(avg - avg2) < 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}