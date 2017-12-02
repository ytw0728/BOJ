#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int n, k;
vector< pair<int,int> > arr;
vector< int > dis;

int cmp(int a, int b) {
	if (a > b) return 1;
	return 0;
}

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back(make_pair(a, b));
	}

	int q = 1;
	int maxv = 0;
	int index = 0;
	long long sum = 0;
	for ( auto i = arr.begin()+1; i != arr.end(); i++) {
		int distance = abs((*(i)).first - (*(i - 1)).first) + abs((*i).second - (*(i - 1)).second);
		dis.push_back( distance );
		if (i > arr.begin() + 1) {
			int now = dis[q] + dis[q - 1];
			if (maxv < now) {
				maxv = now;
				index = q;
			}
			q++;
		}
	}


	for (k;  k != 0; k--) {
		dis[index-1]= 0;
		dis[index] = abs(arr[index-1].first - arr[index+1].first) + abs(arr[index-1].second - arr[index+1].second);
		sort(dis.begin(), dis.end(),cmp);
		dis.pop_back();

		int maxv = 0;
		int q = 1;
		for (auto i = dis.begin() + 1; i != dis.end(); i++, q++) {
			int now = (*i)+ (*(i - 1));
			if (maxv < now) {
				maxv = now;
				index = q;
			}
		}
	}

	for (auto i = dis.begin(); i != dis.end(); i++) {
		sum += *i;
	}

	cout << sum << endl;
	
	return 0;
}