#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
struct aa
{
	int cnt;
	int num;
};

struct cmp
{
	bool operator () (aa& a, aa& b)
	{
		if (a.cnt > b.cnt)
			return true;
		
		if (a.cnt == b.cnt)
		{
			return a.num < b.num;
		}

		return false;
	}
};

int adj[1010][1010] = { 0, };
int temp[1010];
aa cnt[1010];
int flag;

int main() {

	scanf("%d %d", &n, &m);

	while (n && m)
	{
		memset(cnt, 0, sizeof(aa)*(n+1));
		memset(temp, 0, sizeof(int)*(n+1));
		flag = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &temp[j]);
			}

			for (int j = 0; j < n-1; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					adj[temp[j]][temp[k]]++;
				}
			}
		}

		for (int i = 1; i < n + 1; i++)
		{
			cnt[i].num = i;
			for (int j = 1; j < n + 1; j++)
			{
				if (m-(m / 2) <= adj[i][j])
				{
					cnt[i].cnt++;
				}
				adj[i][j] = 0;
			}
		}


		sort(cnt + 1, cnt + n + 1,cmp());
		/*
		for (int i = 1; i < n + 1; i++)
		{
			printf("%d - %d\n", cnt[i].num, cnt[i].cnt);
		}*/

		for (int i = 2; i < n + 1; i++)
		{
			if (cnt[i - 1].cnt == cnt[i].cnt)
				flag++;
		}

		if (flag==0 || flag==n-1)
		{
			for (int i = 1; i < n + 1; i++)
			{
				printf("%d ", cnt[i].num);
			}
		}
		else
			printf("No solution");

		printf("\n");
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}