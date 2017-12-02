#include <stdio.h>
#include <deque>

using namespace std;


void insert( deque<int> &q , int v) {
	int l, r;
	l = 0, r = q.size();
	while ( l < r) {
		int m = (l + r) / 2;

		if (m < q.size()) {
			if( q.begin() + m + 1 == q.end() ){
				if (q[m] <= v) {
					l = m + 1, r = m + 1;
					continue;
				}
			}
			else if (q[m] <= v && v < q[m + 1]) {
				l = m;
				r = m;
				continue;
			}
		}
		if (m > 0) {
			if (q[m - 1] < v && v <= q[m]) {
				l = m;
				r = m;
				continue;
			}
		}
		if (q[m] < v) {
			l = m+1;
			continue;
		}
		if (q[m] > v) {
			r = m;
			continue;
		}

	}

	q.insert(q.begin() + l, v);

}
void del(deque<int> &q, int t) {
	if (q.size() == 0 ) return;
	if (t == 1) {
		q.pop_back();
	}
	else {
		q.pop_front();
	}
}
// D 1 최댓값 delete , D -1 최소값 delete
// I 인서트
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);

		deque<int> q;
		while (k--) {
			char c;
			int temp;
			scanf(" %c %d", &c, &temp);
			switch (c) {
				case 'I': insert(q,temp);  break;
				case 'D': del(q, temp); break;
				default: break;
			}
		}

		if (q.size() == 0) printf("EMPTY\n");
		else printf("%d %d\n", q.back(), q.front());
	}

	return 0;
}