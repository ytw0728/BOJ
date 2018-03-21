#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

vector< pair< long long , long long > > arr;
typedef struct VECTOR {
	long long x;
	long long y;
	long long z;
} VECTOR;

int main() {
	int n;
	scanf("%d", &n);
	int tmpN = n;
	while (tmpN--) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back(make_pair(a, b));
	}

	double s = 0;
	for (int i = 1; i < n - 1; i++) {
		VECTOR v = { arr[i].first - arr[0].first, arr[i].second - arr[0].second , 0 };
		VECTOR w = { arr[i + 1].first - arr[0].first , arr[i + 1].second - arr[0].second , 0 };

		//VECTOR cross = { 0,0 , v.x * w.y - v.y* w.x };
		long long cross = v.x * w.y - v.y * w.x;

		if (cross > 0) s -= sqrt(pow(cross, 2));
		else s += sqrt( pow(cross, 2) );
	}
	printf("%.1lf", fabs(s / 2.0) + 0.005);

	return 0;
}