#include <stdio.h>
#include <queue>

using namespace std;

queue<int> arr;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		sum += temp;
		arr.push(temp);
		while(sum > m) {
			sum -= arr.front();
			arr.pop();
		}

		if (sum == m) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}