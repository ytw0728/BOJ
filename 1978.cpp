#include <cstdio>
#include <vector>

using namespace std;
vector<int> prime;
int primeFrame[1010];

void makePrime() {

	for (int i = 2; i < 505; i++) {
		for (int j = i; j <= 1000; j += i) {
			if (j != i) primeFrame[j] = 1;
		}
	}

	for (int i = 2; i <= 1000; i++) {
		if (!primeFrame[i]) prime.push_back(i);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	makePrime();

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		int exist = 0;
		for (auto q = prime.begin(); q != prime.end(); q++) {
			if (t == *q) {
				exist = 1;
				break;
			}
		}
		cnt += exist;
	}

	printf("%d", cnt);
	return 0;
}