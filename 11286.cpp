#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	priority_queue< pair<int, int> > arr;

	while (n--) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp == 0) {
			if (arr.empty()) printf("0\n");
			else {
				printf("%d\n", -arr.top().second);
				arr.pop();
			}
			continue;
		}

		arr.push( make_pair(-abs(tmp), -tmp));

	}
	return 0;
}