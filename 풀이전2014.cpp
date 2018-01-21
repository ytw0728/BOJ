#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr;
priority_queue<long long> PQ;
int k, n;

void go( int start, int num, long long v) {
	if (num <= 0) return;

	for (int i = start; i <= k; i++) {
		long long t;
		PQ.push(-(t = v*arr[i]) );
		go( i, num - 1, t);
	}
}

int main() {

	scanf("%d %d", &k, &n);

	arr.push_back(-1);
	

	int tmpK = k;
	while (tmpK--) {
		int t;
		scanf("%d", &t);
		
		arr.push_back(t);
	}

	go(1, n, 1);
	
	while (!PQ.empty() && --n) {
		PQ.pop();
	}

	printf("%lld", -PQ.top());


	return 0;
}