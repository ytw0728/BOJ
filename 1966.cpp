#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		
		deque< pair<int, int> > arr;

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			int pri;
			scanf("%d", &pri);
			arr.push_back( make_pair(pri, i) );
		}
		
		int done = 0;
		int cnt = 0;
		while (!done) {
			int move = 0;
			auto i = arr.begin();
			for (auto j = i + 1; j != arr.end(); j++) {
				if ((*i).first < (*j).first) {
					arr.push_back(arr.front());
					arr.pop_front();
					move = 1;
					break;
				}
			}
			if (!move) {
				cnt++;
				if( arr.front().second == m ) break;
				arr.pop_front();
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}