#include <stdio.h>
#include <vector>

using namespace std;

int dy[11];
int n;
int go(int i) {
	if (i < 0 ) return 0;
	if (i == 0 ) return 1;

	int& ret = dy[i];
	if (ret != 0) return ret;

	if (i >= 3) {
		ret += go(i - 3);
	}
	if (i >= 2) {
		ret += go(i - 2);
	}
	if (i >= 1) {
		ret += go(i - 1);
	}

	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int result = go(n);
		printf("%d\n", result);
	}

	return 0;
}