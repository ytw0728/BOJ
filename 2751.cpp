#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int main() {

	int n;
	scanf("%d", &n);

	arr.resize(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr.begin(), arr.end() );


	for (auto i = arr.begin(); i != arr.end(); i++) {
		printf("%d\n", *i);
	}


	return 0;
}