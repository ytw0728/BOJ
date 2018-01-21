#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <functional>

using namespace std;

class Node {
	public:

	private:

};
bool comp(pair< pair< int, int>, pair<int, int> > a, pair< pair< int, int>, pair<int, int> > b) {
	if (a.first.first != b.first.first) return a.first.first > b.first.first;
	if (a.first != b.first) return a.first > b.first;

	return a.second > b.second;
}

int main() {
	int n, m;
	vector<int> v; 
	vector< pair< pair<int, int> , pair<int, int> > > vertex; // <정점, 정점 인덱스>, < 왼쪽 차이 인덱스, 오른쪽 차이 인덱스 >
	vector< pair< pair<int, int> , pair<int, int> > > gap; // <차이, 차이 인덱스> , < 왼쪽 정점 인덱스 , 오른쪽 정점 인덱스 >

	priority_queue< pair< pair< int, int>, pair<int, int> >, vector< pair< pair< int, int>, pair<int, int> > >, decltype(comp) > PG; // 차이 우선순위 큐

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n ;i++){
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}

	auto start = v.begin();
	auto end = v.end()-1;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			int gapTmp = abs(v[i-1] - v[i]);
			gap.push_back(make_pair( make_pair(gapTmp, i-1), make_pair(i-1, i)));
			PG.push(gap.back());
		}
		
		vertex.push_back(make_pair( make_pair(v[i], i) , make_pair( (i==0)? 0 : i-1 , (i==n-1)? i-1: i )));
	}

	while (!PG.empty() && m--) {

		auto nowNode = PG.top();
		if (nowNode.first.first != gap[nowNode.first.second].first.first) {
			m++;
			PG.pop();
			continue;
		}


		int gapIdx = nowNode.first.second;
		int idxLeft = nowNode.second.first;
		int idxRight = nowNode.second.second;
		PG.pop();

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

			whereGap = vertex[idxLeft].second.first;
			gap[whereGap].first.first = abs(v[idxLeft] - v[idxLeft2]);
		}
		else {
			int idxRight2 = idxRight + 1;
			if (idxRight2 > n-1) idxRight2 = n-1;

			vertex[idxRight].first.first--;
			whereGap = vertex[idxRight].second.second;
			gap[whereGap].first.first = abs(v[idxRight] - v[idxRight2] );
		}

		vector< pair< pair<int, int>, pair<int, int> > > stack;

		while (!PG.empty() ){
			if (PG.top().first.second != whereGap) stack.push_back(PG.top());
			else {
				PG.pop();
				break;
			}
			PG.pop();
		}

		while (!stack.empty()) {
			PG.push(stack.back());
			stack.pop_back();
		}

		PG.push(make_pair(make_pair( gap[whereGap].first.first, whereGap ), make_pair( gap[whereGap].second.first, gap[whereGap].second.second)));
		PG.push(make_pair(make_pair(gapTmp , gapIdx ), make_pair( idxLeft, idxRight)));
	}
	
	
	
	for (auto i = v.begin(); i != v.end(); i++) {
		printf("%d ", *i);
	}

	return 0;
}
