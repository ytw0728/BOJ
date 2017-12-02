#include <iostream>
#include <algorithm>
using namespace std;

struct db
{
	int time = 0;
	int score[110] = { 0, };
	int cnt = 0;
	int final_score = 0;
	int id;

	
};

bool cmp(db& a, db& b){
	if (a.final_score > b.final_score)
		return true;
	else if (a.final_score == b.final_score && a.cnt < b.cnt)
		return true;
	else if (a.final_score == b.final_score && a.cnt == b.cnt && a.time < b.time)
		return true;

	return false;
}

int main()
{
	int T, n, k, t, m, id, num, sc;

	scanf("%d", &T);
	for (int p = 1; p < T + 1; p++)
	{
		scanf("%d %d %d %d", &n, &k, &t, &m);

		db adj[110];

		for (int i = 1; i < m + 1; i++)
		{
			scanf("%d %d %d", &id, &num, &sc);
			adj[id].id = id;
			adj[id].cnt++;
			adj[id].time = i;
			adj[id].score[num] = max(adj[id].score[num], sc);
		}

		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < k + 1; j++)
			{
				adj[i].final_score += adj[i].score[j], adj[i].final_score;
			}
		}

		sort(adj+1, adj + n+1, cmp);
		
		for (int i = 1; i < n + 1; i++)
		{
			if (adj[i].id == t)
			{
				printf("%d\n", i);
				break;
			}
			
			//printf("%d : %d %d %d\n", adj[i].id, adj[i].final_score, adj[i].cnt, adj[i].time);
		}
	}

	return 0;
}