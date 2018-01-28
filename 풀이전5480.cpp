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
		long long n; // �׸��� ũ��
		int k, l; // ���� �� , ���� ��
		scanf("%lld %d %d", &n, &k, &l);

		int tempK = k;
		while (tempK--) {
			long long x1, y1, x2, y2; // �����ִ� ���� �簢��
			int w; // ����
			scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2); scanf("%d", &w);
			arr.push_back({ x1, y1, x2, y2, w });	
		}

		int tempL = l;
		while (tempL--) {
			int a, b; // b - 0,1  0 -> ���� (1,a) (n,a), 1 -> ���� (a,1) (a,n)
			lazers.push_back(make_pair(a, b));
		}


	}
	return 0;
}