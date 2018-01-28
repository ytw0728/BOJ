#include <cstdio>
#include <vector>

using namespace std;

int primeFrame[1000010];
vector<int> prime;

int main() {
	for (int i = 2; i < 500005; i++) {
		for (int j = i; j < 1000010; j += i) {
			if (j != i) primeFrame[j] = 1;
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (!primeFrame[i] && i % 2 == 1 ) prime.push_back(i);
	}

	auto end = prime.end();

	while (1) {
		int t;
		scanf("%d", &t);
		if (t == 0) return 0;

		auto i = prime.begin();
		auto j = i;
		int done = 0;
		for (i; i != prime.end(); i++) {
			if (*i >= t) break;
			for (j = i; j != prime.end(); j++) {
				if (*j + *i >= t) break;
			}
			if (i != end && j != end && *j + *i == t) {
				done = 1;
				break;
			}
		}

		if (done) printf("%d = %d + %d\n", t, *i, *j);
		else printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}