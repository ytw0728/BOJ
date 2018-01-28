#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int arr[100] = { 0, };
		long long sum= 0;

		int i = 0;
		int m;
			scanf("%d", &m);
		for( int i = 0; i < m ; i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + m, cmp);

		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}

		printf("%lld\n", sum);
	}
	return 0;
}