#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	
	vector<vector<int>> point;
	vector<vector<int>> dp;
	scanf("%d %d", &n, &m);
	dp.resize(n + 1);
	point.resize(n + 1);
	int tempN = n;
	while (tempN--){
		int a, b;
		scanf("%d %d", &a, &b);
		point[a].push_back(a+b);
	}

	sort(point.begin(), point.end());


	
	
}