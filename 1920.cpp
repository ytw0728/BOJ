#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> xs;

void bs(int left, int right, int x) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] < x) left = mid + 1;
		else right = mid;
	}

	if (arr[left] == x) printf("1\n");
	else printf("0\n");

}
int main() {
	int n,m;
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr.begin(), arr.end());

	scanf("%d", &m);
	xs.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &xs[i]);
	}

	for (auto i : xs) {
		bs(0,arr.size()-1, i);
	}
	return 0;
}