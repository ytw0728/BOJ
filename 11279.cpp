#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> arr;

	int n;
	scanf("%d", &n);

	while (n--) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp == 0) {
			if (arr.empty()) printf("0\n");
			else {
				printf("%d\n", arr.top());
				arr.pop();
			}
			continue;
		}

		arr.push(tmp);
	}

	return 0;
}