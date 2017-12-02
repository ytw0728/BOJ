#pragma warning (disable: 4996)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr;
vector<int> maximum;
vector<int> m;
vector<int> num;
int main() {
	int testCase;
	scanf("%d", &testCase);

	int n;
	int index_m = 0;
	int index_a;
	m.resize(testCase);
	maximum.resize(testCase);
	arr.resize(testCase);

	for (int i = 0; i < testCase; i++) {
		scanf("%d", &n);
		num.push_back(n);
		arr[i].resize(n);
		cin >> m[i];
		cin >> maximum[i];
		for (index_a = 0; index_a < n; index_a++) {
			cin >> arr[i][index_a];
		}
	}
	
	queue<int> q;
	int value = 0;
	int count = 0;

	for (int i = 0; i < testCase; i++) {
		auto v = arr[i].begin();
		value = 0;
		count = 0;
		int loop;
		while ( !q.empty() ) q.pop();
		if (num[i] == m[i]) loop = num[i];
		else loop = num[i] + m[i] - 1;

		for (int l = 0; l < loop; l++) {
			value += *v;
			q.push(*v);
			while (value >= maximum[i] && !q.empty()) {
				value -= q.front();
				q.pop();
			}
			if (q.size() >= m[i] ) count++;

			v++;
			if (v == arr[i].end()) v = arr[i].begin();
		}
		printf("%d\n", count);
	}


	return 0;
}