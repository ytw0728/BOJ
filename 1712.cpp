#include <stdio.h>
#include <limits.h>

using namespace std;


int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (b >= c) {
		printf("-1\n");
		return 0;
	}
	
	int cnt = 0;

	long long total = 0;
	total += a;
	long long benefit = 0;

	while(cnt <= INT_MAX) {
		total += b;
		benefit += c;
		cnt++;
		if (total < benefit ) break;
	}

	if (cnt == INT_MAX && total >= benefit) {
		printf("-1\n");
		return 0;
	}

	printf("%d", cnt);

	return 0;
}
