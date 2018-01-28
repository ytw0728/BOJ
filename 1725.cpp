#include <cstdio>
#include <vector>

using namespace std;

int input[100001];
vector<int> stack;
int maximum;

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		while (!stack.empty() && input[stack.back()] > input[i]) {
			int j = stack.back();
			stack.pop_back();
			int w = i;
			if (!stack.empty()) w -= stack.back() + 1;
			int tmp = w * input[j];
			maximum = tmp > maximum ? tmp : maximum;
		}
		stack.push_back(i);
	}

	while (!stack.empty()) {
		int j = stack.back();
		stack.pop_back();
		int w = n;
		if (!stack.empty()) w -= stack.back() + 1;
		int tmp = w * input[j];
		maximum = tmp > maximum ? tmp : maximum;
	}

	printf("%d\n", maximum);
	return 0;
}