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
		if (!primeFrame[i]) prime.push_back(i);
	}

	auto end = prime.end();

	int t;
	scanf("%d", &t);
	if (t == 0) return 0;
	
	if (t < 8) {
		printf("-1\n");
		return 0;
	}

	int tmpT = t;
	
	auto i = prime.begin();
	auto j = i;

	int k = 2;
	int l = 2;
	if (t % 2) l = 3;
	
	t -= k + l;

	int done = 0;

	for (i; !done && i != end; i++) {
		if (*i >= t) break;
		for (j = i; !done && j != end; j++) {
			if (*j + *i >= t) {
				done = ((*j + *i) == t);
				break;
			}
		}
		if (done) break; 
	}

	if (done) printf("%d %d %d %d\n", k, l, *i, *j);
	else printf("-1\n");


	return 0;
}