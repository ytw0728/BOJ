#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair< int, int > > arr;
vector< pair< int, int> > classes;


pair<int, int > p[400001];


int main() {
	int num = 1;
	int n;
	scanf("%d", &n);
	int tmpN = n;
	
	while (tmpN--) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back(make_pair(a, b));
	}
	
	sort(arr.begin(),arr.end());
	
	auto last = arr[0];
	
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].first >= last.second)
			last = arr[i];
		else if (arr[i].second <= last.second) {
			bool done = false;
			auto index = classes.begin();
			for (index;index != classes.end(); index++ ) {
				if ( done = ( (*index).second <= last.first) ) break;
			}
			if (done) (*index).second = last.second;
			else {
				classes.push_back(last);
				num++;
			}
			last = arr[i];
		}
		else if (arr[i].first < last.second) {
			bool done = false;
			auto index = classes.begin();
			for (index; index != classes.end(); index++) {
				if (done = ((*index).second <= arr[i].first)) break;
			}
			if (done) (*index).second = arr[i].second;
			else {
				classes.push_back(arr[i]);
				num++;
			}
		}
	}
		
	printf("%d\n", num);
	
	return 0;
}