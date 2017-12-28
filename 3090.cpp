#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main() {
	int n, m;
	vector<int> v; 
	vector< pair< pair<int, int> , pair<int, int> > > vertex; // <정점, 정점 인덱스>, < 왼쪽 차이 인덱스, 오른쪽 차이 인덱스 >
	vector< pair< pair<int, int> , pair<int, int> > > gap; // <차이, 차이 인덱스> , < 왼쪽 정점 인덱스 , 오른쪽 정점 인덱스 >

	priority_queue< pair< pair<int, int>, pair<int, int> > > PG; // 차이 우선순위 큐

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n ;i++){
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}

	auto start = v.begin();
	auto end = v.end()-1;
	for (int i = 0; i < n; i++) {
		if (i != n-1) {
			int gapTmp = abs(v[i] - v[i + 1]);
			gap.push_back(make_pair( make_pair(gapTmp, i), make_pair(i, i + 1)));
			PG.push(gap.back());
		}
		
		int leftGap = 0, rightGap = 0;
		if (i != 0) leftGap = abs(v[i] - v[i - 1]);
		if (i != n) rightGap = abs(v[i] - v[i + 1]);

		vertex.push_back(make_pair( make_pair(v[i], i) , make_pair( i, (i==n-1)?i : i+1 ) ) );
	}

	while (!PG.empty() && m--) {
		if (PG.top().first.first != gap[PG.top.first.second].first.first) {
			m++;
			PG.pop();
			continue;
		}

		int idxLeft = PG.top().second.first;
		int idxRight = PG.top().second.second;
		
		int which = 1;
		if (v[idxLeft] >= v[idxRight]) {
			v[idxLeft]--;
		}
		else {
			v[idxRight]--;
			which = 0;
		}

		int gapTmp = abs(v[idxLeft] - v[idxRight]);

		int whereGap = 0;
		if (which) {
			int idxLeft2 = idxLeft - 1;
			if (idxLeft2 < 0) idxLeft2 = 0;

			vertex[idxLeft].first.first--;
			gap[vertex[idxLeft].second.first].first.first = abs(v[idxLeft] - v[idxLeft2]);
			whereGap = vertex[idxLeft].second.first;
		}
		else {
			int idxRight2 = idxRight + 1;
			if (idxRight2 > n-1) idxRight2 = n-1;

			vertex[idxRight].first.first--;
			gap[vertex[idxRight].second.second].first.first = abs(v[idxRight] - v[idxRight2] );
			whereGap = vertex[idxRight].second.second;
		}

		vector< pair< pair<int, int>, pair<int, int> > > stack;

		while (!PG.empty() ){
			if (PG.top().first.second != whereGap) stack.push_back(PG.top());
			else break;
			PG.pop();
		}
		PG.pop();

		while (!stack.empty()) {
			PG.push(stack.back());
			stack.pop_back();
		}

		PG.push(make_pair(make_pair( , whereGap ), make_pair( , )));
	}
	
	
	
	for (auto i = v.begin(); i != v.end(); i++) {
		printf("%d ", *i);
	}

	return 0;
}