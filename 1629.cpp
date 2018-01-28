#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

vector<int> arr;
long long a, b, c;

long long go(long long q, int w) {
	if (w <= 0) return 1;
	if (w == 1) return q%c;
	long long tmp = go(q%c, w/2)%c;
	if (w % 2) return ( ((tmp*tmp)%c) * (q%c) )%c;
	else return ( tmp*tmp )%c;
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	
	long long result = go(a%c, b);

	printf("%lld", result);
	return 0;
}
