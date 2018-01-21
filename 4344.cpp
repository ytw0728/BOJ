#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;



int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> arr;
		double sum = 0;
		int tmpN = n;

		while (tmpN--) {
			int tmp;
			scanf("%d", &tmp);
			arr.push_back(tmp);
			sum += tmp;
		}

		double avg = sum / n;

		double cnt = 0;
		for (auto i = arr.begin(); i != arr.end(); i++) {
			if (*i > avg) cnt++;
		}

		cnt = (cnt / n) * 100;

		printf("%.3lf%%\n", cnt);
	}

	return 0;
}