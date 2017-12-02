#include <stdio.h>
#include <math.h>
#define MAX_N 10000000
using namespace std;

bool arr[MAX_N + 1];

int n;
void make() {
	int until = sqrt(MAX_N);
	for (int i = 2; i <= until; i++) {
		if (!arr[i]) {
			for (int j = i*i; j <= n; j+=i) {
				arr[j] = true;
			}
		}
	}
}
void divide(int a){
	int i = 2;
	while (a > 1) {
		while ( arr[i] == false && a%i == 0) {
			printf("%d\n", i);
			a /= i;
		}
		i++;
	}
}
int main() {
	scanf("%d", &n);
	make();
	divide(n);
	return 0;
}