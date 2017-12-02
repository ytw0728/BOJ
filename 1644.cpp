#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

queue<int> arr;
bool chk[4000001];
int sum = 0;
int cnt = 0;

void find(int t){
	chk[0] = chk[1] = true;

	for (int i = 2; i <= sqrt(t); i++) {
		if (!chk[i]) {
			for (long long j = i*i; j <= t; j+=i) {
				chk[j] = true;
			}
		}
	}

	for (int i = 2; i <= t; i++) {
		if (!chk[i] && i != t ) {
			arr.push(i);
			sum += i;
			while (sum > t) {
				sum -= arr.front();
				arr.pop();
			}
			if (sum == t) cnt++;
			if (i > t / 2) break;
		}
	}

	if (!chk[t]) cnt++;
	printf("%d", cnt);
}


int main() {
	int n;
	scanf("%d", &n);

	find(n);

	return 0;
}