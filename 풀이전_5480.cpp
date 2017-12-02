#include <stdio.h>
#include <vector>
#define ll long long

using namespace std;

struct ships {
	ll x1;
	ll y1;
	ll x2;
	ll y2;
	int w;
};

vector<pair<int, int>> lazers;
vector<ships> arr;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		arr.clear();
		lazers.clear();
		long long n; // 그리드 크기
		int k, l; // 전함 수 , 대포 수
		scanf("%lld %d %d", &n, &k, &l);

		int tempK = k;
		while (tempK--) {
			long long x1, y1, x2, y2; // 전함있는 구역 사각형
			int w; // 무게
			scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2); scanf("%d", &w);
			arr.push_back({ x1, y1, x2, y2, w });	
		}

		int tempL = l;
		while (tempL--) {
			int a, b; // b - 0,1  0 -> 수평 (1,a) (n,a), 1 -> 수직 (a,1) (a,n)
			lazers.push_back(make_pair(a, b));
		}


	}
	return 0;
}