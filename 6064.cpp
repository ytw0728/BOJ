#include <cstdio>
#include <deque>

using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a%b);
}

long long lea(int a, int b) {
	return a*b / gcd(a, b);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		long long m, n, x, y;
		scanf("%lld %lld %lld %lld", &m, &n, &x, &y);
		long long until = lea(m, n);

		long long answer = -1;
		long long left = x, right = y;

		while ( x <= until && y <= until ) {
			if (x < y) {
				x += m;
			}
			else if (x > y) {
				y += n;
			}
			if (x == y) {
				answer = x;
				break;
			}
		}
		if (answer > until) answer = -1;
		printf("%lld\n", answer);
	}
	return 0;
}