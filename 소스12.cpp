#include <stdio.h>
#include <vector>

using namespace std;


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n, d;
		vector< pair<int,int> > hp;
		scanf("%d %d", &n, &d);
		for (int q = 1; q <= n; q++) {
			int temp;
			scanf("%d", &temp);
			hp.push_back( make_pair(temp, q) );
		}


		int index = 0;
		int dir = 1;
		
		auto a = hp.begin();
		int last = 0;


		for (int q = 1; q <= n + 5 && hp.size() > 0; q ++) {
			last = hp[index].second;
			if (hp[index].first - d <= 0) {
				dir = -dir;

				if (a == hp.end() -1 ) index = dir == 1 ? index-1 : 0;
				else if (a == hp.begin() ) index = dir == 1 ? hp.size()-2 : index;
				else index = dir == 1 ? index-1 : index;
				hp.erase( a );
				if (hp.size() == 0 ) break;
				a = hp.begin() + index;
			}
			else {
				hp[index].first -= d;
			}
			
			if ( dir == 1 && a + dir == hp.end()) {
				a = hp.begin();
				index = 0;
			}
			else if (dir == -1  && a == hp.begin() ) {
				a = hp.end() - 1;
				index = hp.size() -1 ;
			}
			else {
				a += dir;
				index += dir;
			}
		}

		printf("%d\n", last);
	}
	return 0;
}