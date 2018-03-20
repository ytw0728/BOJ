#include <cstdio>

using namespace std;

long long arr[105];
int main() {
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		if (arr[n]) {
			printf("%lld\n", arr[n]);
			continue;
		}

		int idx1 = 1, idx2 = 5;
		for (int i = 6; i <= n; i++) {
			arr[i] = arr[idx1] + arr[idx2];
			idx1++;
			idx2++;
		}

		printf("%lld\n", arr[n]);
	}
		
	return 0;
}