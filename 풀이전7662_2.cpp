#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

priority_queue<pair<long long,int > > maxQ;
priority_queue<pair<long long,int > > minQ;
int willDel[100005];

void del(priority_queue<pair<long long, int > >& q) {
	if (q.empty()) return;
	willDel[q.top().second] = 1;
	q.pop();
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int k;
		scanf("%d", &k);
		getchar();
		int index = 0;

		while (!maxQ.empty()) maxQ.pop();
		while (!minQ.empty()) minQ.pop();

		while (k--) {
			char term;
			long long num;
			scanf("%c %lld", &term, &num);
			getchar();
			if (term == 'D') {
				num == 1 ? del(maxQ) : del(minQ);
				while (!maxQ.empty() && willDel[maxQ.top().second]) maxQ.pop();
				while (!minQ.empty() && willDel[minQ.top().second]) minQ.pop();
			}
			else{
				willDel[index] = 0;
				maxQ.push(make_pair(num, index));
				minQ.push(make_pair(-num, index++));
			}
		}


		if (maxQ.empty() || minQ.empty() ) printf("EMPTY\n");
		else printf("%lld %lld\n", maxQ.top().first, -minQ.top().first);
	}
	return 0;
}