#include <cstdio>
#include <algorithm>

using namespace std;

int records[100005];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	long long sum = 0;
	for (int i = 0; i < n; i ++ ) {
		scanf("%d", &records[i]);
		sum += records[i];
	}
	
	long long left, right, mid;
	left = 1, right = sum;
	
	while (left < right) {
		mid = (left + right) / 2;

		int cnt = 0;
		int idx = 0;
		while (idx < n && cnt <= m) {
			long long tmpSum = 0;
			while (tmpSum + records[idx] <= mid && idx < n) {
				tmpSum += records[idx];
				idx++;
			}
			cnt++;
		}

		if (cnt > m) left = mid +1;
		else if (cnt <= m) right = mid;
	}
	
	printf("%d\n", right);

	return 0;
}