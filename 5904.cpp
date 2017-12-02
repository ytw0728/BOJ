#include <stdio.h>
#include <vector>

using namespace std;

vector<int> length;

char deep(int k, int n) {
	char result;
	if (n == 0) {
		(k == 1) ? result = 'm' : result = 'o';
		return result;
	}

	if (k <= length[n - 1]) return deep(k, n - 1);
	else if (k <= length[n - 1] + 1 + n + 2) {
		k -= length[n - 1];
		(k == 1) ? result = 'm' : result = 'o';
		return result;
	}
	else {
		k -= length[n - 1] + 1 + n + 2;
		return deep(k, n - 1);
	}
}

int main() {
	int k;
	int n;
	scanf("%d", &k);

	int temp = 3;
	length.push_back(3);
	for (int i = 1; ; i++) {
		temp = length.back() * 2 + (i + 2) + 1;
		length.push_back(temp);
		if(temp > k) {
			n = i;
			break;
		}
	}

	char result = deep(k, n);

	printf("%c", result);

	return 0;
}