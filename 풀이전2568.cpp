#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair< int, int > > arr;
vector< pair<int, int> > answer;

int find(int v) {
	int l = 0, r = answer.size() - 1;
	int mid = 0;
	while ( l < r ) {
		mid = (l + r) / 2;
		if (answer[mid].second < v) l = mid + 1;
		else r = mid;
	}

	return mid;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back(make_pair(b, a));
	}

	sort(arr.begin(), arr.end());

	return 0;
}