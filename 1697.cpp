#include <cstdio>
#include <queue>

using namespace std;

int dis[200010];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	if (n >= k) {
		printf("%d", n - k);
		return 0;
	}

	queue< int > q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == k) continue;

		if (now + 1 <= k) {
			if (!dis[now + 1]) {
				dis[now + 1] = dis[now] + 1;
				q.push(now + 1);
			}
			else if (dis[now + 1] > dis[now] + 1) {
				dis[now + 1] = dis[now] + 1;
				q.push(now + 1);
			}
		}
		if (now - 1 <= k && now - 1 >= 0 ) {
			if (!dis[now - 1]) {
				dis[now - 1] = dis[now] + 1;
				q.push(now - 1);
			}
			else if(dis[now - 1] > dis[now] + 1){
				dis[now - 1] = dis[now] + 1;
				q.push(now - 1);
			}
		}
		if (now * 2 <= 200000) {
			if (now * 2 <= k) {
				if (!dis[now * 2]) {
					dis[now * 2] = dis[now] + 1;
					q.push(now * 2);
				}
				else if (dis[now * 2] > dis[now] + 1) {
					dis[now * 2] = dis[now] + 1;
					q.push(now * 2);
				}
			}
			else {
				if (!dis[k]) dis[k] = now * 2 - k + 1 + dis[now];
				else if (dis[k] > now * 2 - k + 1 + dis[now]) {
					dis[k] = now * 2 - k + 1 + dis[now];
				}
			}
		}
	}

	printf("%d\n", dis[k]);

	return 0;
}