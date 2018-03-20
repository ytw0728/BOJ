#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int> > arr;
long long num[200005];
long long result[200005];

int main() {
	int n;
	scanf("%d", &n);

	for( int i =0 ;i< n	 ;i++){
		int a, b;
		scanf("%d %d", &a, &b);

		arr.push_back(make_pair(make_pair(b, a), i));
	}

	sort(arr.begin(), arr.end());

	long long totalSize = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		for (; arr[j].first.first < arr[i].first.first; j++) {
			totalSize += arr[j].first.first;
			num[arr[j].first.second] += arr[j].first.first;
		}
		result[arr[i].second] = totalSize - num[arr[i].first.second];
	}

	for (int i = 0; i < n; i++) {
		printf("%lld\n", result[i]);
	}

	return 0;
}