#include <stdio.h>
#include <queue>
#include <algorithm>


using namespace std;


priority_queue< pair< int, int> > PQ;

int main() {
	int n;
	scanf("%d", &n);


	for( int p = 1; p <= n ; p++){
		int arr[5];
		for (int i = 0; i < 5; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + 5);
		int num = 0;
		int max = -1;
		do {
			num = 0;
			for (int i = 0; i < 3; i++) {
				num += arr[i];
			}
			num %= 10;
			max = max < num ? num : max;
		} while ( next_permutation(arr, arr + 5) );

		PQ.push(make_pair(max, p));
	}

	printf("%d\n", PQ.top().second);
	return 0;
}