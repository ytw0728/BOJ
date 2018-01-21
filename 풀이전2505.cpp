#include <stdio.h>
#include <vector>

using namespace std;
vector<int> arr;

int main() {

	int n;
	scanf("%d", &n);

	int tmpN = n;
	while (tmpN--) {
		int t;
		scanf("%d", &t);
		arr.push_back(t);
	}

	int serial = 1;
	int past = *(arr.begin());

	vector<int> result;
	result.resize(4);
	int cnt = 0;
	int idx = 0;

	int spotCondition = -1;
	int leftCnt = 0;
	int rightCnt = 0;
	auto i = arr.begin()+1;
	for ( ; i != arr.end(); i++, idx++) {
		if (serial) {
			if( past > *i ){
				if (spotCondition == serial) {
					result[leftCnt] = idx;
					serial = 0;
				}
				else {
					
				}
			}
			
		}
		else {
			if (past > *i) {

			}
			else {
				result.push_back(idx);
				serial = 1;
			}
		}

		past = *i;
	}

	return 0;
}