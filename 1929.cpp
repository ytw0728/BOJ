#include <cstdio>

using namespace std;

int primeFrame[1000010];

int main() {
	primeFrame[0] = primeFrame[1] = 1;
	for (int i = 2; i < 500005; i++) {
		for (int j = i; j <= 1000000; j += i) {
			if( j != i ) primeFrame[j] = 1;
		}
	}

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = n; i <= m; i++) {
		if (!primeFrame[i]) printf("%d\n", i);
	}
	return 0;
}