#include <cstdio>
#include <algorithm>

using namespace std;

int woods[1000005];

bool cmp(int a, int b) {
	return a > b;
}
int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int maximum = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &woods[i]);
		maximum = maximum < woods[i] ? woods[i] : maximum;
	}

	sort(woods, woods + n, cmp);

	int left, right, mid;
	left = 0; right = maximum;

	while ( left < right ) {
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n && woods[i] > mid; i++) {
			sum += woods[i] - mid;
		}

		if (sum == m) break;
		else if (sum > m) left = mid + 1;
		else right = mid;
	}

	long long sum = 0;
	for (int i = 0; i < n && woods[i] > mid; i++) {
		sum += woods[i] - mid;
	}
	if (sum < m) mid--;
	
	printf("%d\n", mid);
	return 0;
}