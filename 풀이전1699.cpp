#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	while (n > 0) {

		int minus = 1;
		for (minus; minus * minus <= n; minus++);

		minus--;
		n -= minus*minus;
		cnt++;
	}


	printf("%d\n", cnt);

	return 0;
}