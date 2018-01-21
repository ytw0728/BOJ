#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector< int > xArr;
vector< int > yArr;
int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	
	int tmpM = m;
	while (tmpM--) {
		int a, b;
		scanf("%d %d", &a, &b);

		xArr.push_back(a);
		yArr.push_back(b);
	}

	sort(xArr.begin(), xArr.end());
	sort(yArr.begin(), yArr.end());

	long long d = 0;


	int x = xArr[m/2], y = yArr[m/2];

	for (int i = 0; i < m; i++) {
		d += abs(x - xArr[i]) + abs(y - yArr[i]);
	}

	printf("%d\n", d);
	
	return 0;
}