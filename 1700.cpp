#include <cstdio>
#include <vector>

using namespace std;

int pattern[101];
int plug[101];
int chk[101];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++) {
		scanf("%d", &pattern[i]);
	}

	int cnt = 0;
	int until = 0;
	for (int i = 0; i < k; i++) {
		if (chk[pattern[i]]) continue;

		if (until < n) {
			plug[until++] = pattern[i];
			chk[pattern[i]] = 1;
		}
		else {
			int max = -1, idx;
			for (int j = 0; j < until; j++) {
				int sum = 0;
				for (int q = i; q < k; q++) {
					if (plug[j] != pattern[q]) sum++;
					else break;
				}
				if (sum > max) {
					max = sum;
					idx = j;
				}
			}
			chk[plug[idx]] = 0;
			plug[idx] = pattern[i];
			chk[pattern[i]] = 1;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}

