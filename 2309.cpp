#include <algorithm>

using namespace std;

int main() {
	int height[9];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	int sum = 0;
	do {
		sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += height[i];
		}
		if (sum == 100) break;
	} while (next_permutation(height, height + 9));

	sort(height, height + 7);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", height[i]);
	}

	return 0;
}