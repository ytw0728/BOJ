#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>

using namespace std;

priority_queue< int > PQ;
deque< string> arr[201];

int main() {
	int t;
	scanf("%d", &t);

	int tmpT = t;

	while (tmpT--) {
		int tmpInt;
		string tmp;

		scanf("%d", &tmpInt);
		cin >> tmp;
		PQ.push( -tmpInt );
		arr[tmpInt].push_back(tmp);
	}

	while (!PQ.empty()) {
		int idx = -PQ.top();
		while (!arr[idx].empty()) {
			printf("%d %s\n", idx, arr[idx].front().c_str() );
			arr[idx].pop_front();
		}
		PQ.pop();
	}

	return 0;

}