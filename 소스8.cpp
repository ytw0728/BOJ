#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int m, n;
	int tmp,cnt;
	int a[20];
	bool flag=true;

	while (1)
	{
		cnt = 0;
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
			break;

		memset(a, 0, sizeof(int)*m);

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &a[i]);
		}

		for (int i = 0; i < n; i++)
		{
			flag = true;
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &tmp);
				if (tmp > a[j])
					flag = false;
			}

			if (flag)
				cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}