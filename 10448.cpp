#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n = 1;

	int t;
	scanf("%d", &t);
	vector<int> arr;

	
	for( int i = 1; (n = i*(i + 1) / 2) <= 1000; i++){
		arr.push_back(n);
	}

	int arrSize = arr.size()-1;

	while (t--) {
		int num;
		scanf("%d", &num);

		int tmpNum = num;

		int i, j, k;
		int done = 0;

		for (int i = 0; !done && i <= arrSize; i++) {
			for (int j = 0; !done && j <= arrSize; j++) {
				for (int k = 0; !done && k <= arrSize; k++) {
					if (arr[i] + arr[j] + arr[k] == num) done = 1;
					else if (arr[i] + arr[j] + arr[k] > num) break;
				}
				if (arr[i] + arr[j] > num) break;
			}
		}

		printf("%d\n", done);
	}
	return 0;
}