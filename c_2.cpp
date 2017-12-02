#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{

	int a[100010];
	int b[100010];
	int c, m, c1, c2,t,d,ma;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		ma = -99999;
		scanf("%d %d", &c, &m);
		memset(a, 0, sizeof(int)*c);
		memset(b, 0, sizeof(int)*c);

		for (int j = 1; j < c ; j++)
		{
			scanf("%d %d %d", &c1, &c2, &d);

			a[c2] = max(a[c2], d + a[c1]);

			if (c1==1)
			
		}

		for (int j = 2; j < c + 1; j++)
		{
			if (a[j] > ma)
				ma = a[j];
		}

		if (ma < m)
			printf("-1\n");
		else
			printf("%d\n", ma);
	}

	return 0;
}