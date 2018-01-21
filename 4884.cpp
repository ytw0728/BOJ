#include <stdio.h>
#include <math.h>
#define BINMAX 41


long long binPow[BINMAX];

int main() {

	for (int i = 0; i <= 40; i++) binPow[i] = pow(2, i);

	while (1) {
		long long g,t,a, d;
		scanf("%lld %lld %lld %lld", &g, &t, &a, &d);
		if (g == -1) return 0;

		printf("%lld*%lld/%lld+%lld=", g, a, t, d);

		long long tonaTeam = g*a + d;

		int i = BINMAX;
		while (i > 0 && binPow[i - 1] >= tonaTeam) i--;

		long long x = 0, y = 0;
		y = binPow[i] - tonaTeam;

		x = (t*(t - 1) / 2)*g;

		for (--i; i >= 0; i--) x += binPow[i];

		printf("%lld+%lld\n", x, y);
	}
	return 0;
}