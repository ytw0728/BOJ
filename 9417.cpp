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
		int arr[100];
		int maximum = -1;
		int i = 0;
		int cnt = 0;
		while (1) {
			scanf("%d", &arr[i++]);
			cnt++;
			char c = getchar();
			if (c == '\n') break;
		}
		sort(arr, arr + cnt, cmp);

		for (int i = 0; i < cnt; i++) {
			for (int j = i + 1; j < cnt; j++) {
				maximum = max( maximum, gcd(arr[i], arr[j]));
			}
		}
		printf("%d\n", maximum);
	}
	return 0;
}