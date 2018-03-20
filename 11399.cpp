#include <cstdio>
#include <algorithm>

using namespace std;

int v[1005];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	long long result= 0;
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		sum += v[i];
		result += sum;
	}

	printf("%lld\n", result);


	return 0;
}