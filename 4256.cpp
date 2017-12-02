#include <stdio.h>

int pre[1010];
int in[1010];
int index = 0;
int n;
void sol(int l, int r, int m, int v) {

	if (l < m) {
		int i;
		index++;
		for (i = 0; pre[index] != in[i] && i < m; i++);
		sol(l, m - 1, i, in[i]);
	}
	if (m < r) {
		int i;
		index++;
		for (i = m+1; pre[index] != in[i] && i < r; i++);
		sol(m+1, r, i, in[i]);
	}
	
	printf("%d ", in[m]);
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int k = 0; k < t; k++)
	{
		scanf("%d", &n);
		index = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &pre[i]);
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &in[i]);
		}
		int i;
		for (i = 0; pre[index] != in[i] && i < n; i++);
		sol(0, n-1,i ,pre[0] );
		printf("\n");
	}
}