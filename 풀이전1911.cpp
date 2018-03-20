#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long > > point;

int main() {
	int N, L;
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a > b) {
			long long tmp;
			tmp = a;
			a = b;
			b = tmp;
		}

		point.push_back(make_pair(a, b));
	}

	int cnt = 0;
	sort(point.begin(), point.end());

	auto i = point.begin();
	pair<long long, int > last = make_pair( (*i).first, ((*i).second - (*i).first)/L + ((((*i).second- (*i).first) % L )? 1 : 0) );
	i++;
	auto end = point.end();

	for (; i != end; i++) {
		long long len = ((*i).second - (*i).first) / L + ((((*i).second - (*i).first) % L) ? 1 : 0);
		int tmp;

		if (len + last.second > ( tmp = (((*i).second - last.first) / L + ((((*i).second - last.first) % L) ? 1 : 0) )) ){
			last.second = tmp;
		}
		else {
			cnt += last.second;
			last.first = (*i).first;
		}
	}

	cnt += last.second;

	printf("%d\n", cnt);

	return 0;
}