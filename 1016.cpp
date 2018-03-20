#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;


bool primeFrame[1000005];
vector<long long> prime;

bool chk[1000005];

int main() {
	long long min, max;
	scanf("%lld %lld", &min, &max);

	long long until = sqrt(max);
	until++;

	for (long long i = 2; i <= until; i++) {
		for (long long j = 2 * i; j <= until; j += i) {
			primeFrame[j] = true;
		}
	}

	for (long long i = 2; i <= until; i++) {
		if ( !primeFrame[i] ) prime.push_back(i);
	}

	until--;
	long long cnt = max - min + 1;

	int idx = 0;
	int size = prime.size();

	while ( idx < size && prime[idx] <= until ) {
		long long tmp = prime[idx];
		while (tmp <= until && tmp > 0 ) {
			long long t = tmp * tmp;
			long long start = (min / t) * t;
			while (start <= max &&start >= 0) {
				if (start >= min && !chk[start-min]) {
					cnt--;
					chk[start-min] = 1;
				}
				start += t;
			}
			tmp *= tmp;
		}
		idx++;
	}

	printf("%lld\n", cnt );

	return 0;
}