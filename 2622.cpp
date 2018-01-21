#include <stdio.h>
#include <tuple>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



int main() {
	int n;
	scanf("%d", &n);

	set< tuple<int,int,int> > s;

	int a, b, c;
	
	a = n / 2;
	b = a;
	c = 0;
	if (a + b == n) b--;
	c++;

	
	int cnt = 0;

	for (a; a > 0 && b > 0 && c > 0; a--) {
		b = a;
		c = 1;
		if( a+b+c<n) c = n - (a+b);
		else if (a + b + c > n) b = n - (a + c);
		if ( a < b || b < c || a == b + c) continue;
		
		/*
		int tmpB = b;
		int tmpC = c;
		while (tmpB >= tmpC) {
			tmpB--;
			tmpC++;	
			cnt++;
		}
		*/
		

		cnt += (b - c - 1) / 2 + 1;
		if (b != c && (b - c - 1) % 2) cnt++;
	}

	cout << cnt << endl;
	return 0;
}