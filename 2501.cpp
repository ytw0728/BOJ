#include <cstdio>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n/2+1; i++) {
		if (n % i == 0) k--;
		if (k == 0) {
			printf("%d\n", i);
			return 0;
		}
	}

	if (k == 1) printf("%d\n", n);
	else printf("0\n");

	return 0;
}