#include <cstdio>
#include <vector>

using namespace std;

vector<int> coin;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	coin.resize(n);
	int tmpN = n;

	while (tmpN--) {
		scanf("%d", &coin[tmpN]);
	}

	int cnt = 0;
	int idx = 0;

	while (k > 0 && idx < n) {
		cnt += k / coin[idx];
		k %= coin[idx];
		idx++;
	}


	printf("%d\n", cnt);

	return 0;
}