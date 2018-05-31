#include <cstdio>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	if (n <= 1) {
		printf("1\n");
	}
	else if ( n == 2){
		if (m <= 6) printf("%d\n", (m-1)/ 2+1);
		else printf("4\n");
	}
	else {
		if (m <= 3) printf("%d\n",m);
		else if (m <= 6) printf("4\n");
		else printf("%d\n", m-2);
	}
	

	return 0;
}