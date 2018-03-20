#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


vector< pair<int, int> > arr;
int main() {
	int n;
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr.begin(), arr.end() );

	int cnt = 0;
	pair< int, int > last = *(arr.begin());

	for (auto i = arr.begin() + 1; i != arr.end(); i++) {
		if ((*i).second < last.second) {
			last = *i;
		}
		else if( (*i).first >= last.second ){
			cnt++;
			last = *i;
		}
	}


	printf("%d\n", cnt + 1);
	return 0;
}