#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;
vector<int> l;
vector<int> r;
void dp() {
}
int main() {
	int testCase;
	cin >> testCase;

	int temp;
	for (int i = 0; i < testCase; i++) {
		cin >> temp;
		l.push_back(temp);
	}

	for (int i = 0; i < testCase; i++) {
		cin >> temp;
		r.push_back(temp);
	}

	dp();

	return 0;
}
