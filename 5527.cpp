#include <cstdio>
#include <vector>

using namespace std;

typedef struct node {
	int start;
	int end;
	int length;

	bool operator < (const node A)const {
		return length < A.length;
	}
}node;

bool arr[100005];
vector< node > periods; // pulsing periods

int main() {
	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	node period = { 0 , -1 , 0 };
	for (int i = 0; i < n; i++) {
		if ( arr[i] == arr[i+1] || i == n - 1 ){
			period.end = i;
			period.length = period.end - period.start + 1;

			periods.push_back(period);
			period = { i+1, -1, 0 };
		}
	}

	int maximum = -1;
	int until = periods.size();
	for (int i = 0; i < until; i++) {
		int left = i - 1;
		int right = i + 1;
		int sum = periods[i].length;
		if (left >= 0) sum += periods[left].length;
		if (right < until ) sum += periods[right].length;

		maximum = maximum < sum ? sum : maximum;
	}

	printf("%d\n", maximum);

	return 0;
}