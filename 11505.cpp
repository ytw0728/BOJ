#include <cstdio>
#include <cstring>
#define MOD 1000000007

using namespace std;

int n, m, k;
int arr[1000005];
long long t[4000005];

long long tree(int idx, int a, int b){
	if (a == b) return (t[idx] = arr[a]);
	else return t[idx] = ( tree(2 * idx, a, (a + b) / 2) * tree(2 * idx + 1, (a + b) / 2 + 1, b) )%MOD;
}

long long update(int targetIdx, int v, int now, int a, int b) {
	if (a == b) return (t[now] = v);

	if (targetIdx <= (a + b)/2 ) return t[now] = ( update(targetIdx, v, 2 * now, a, (a + b) / 2) * t[2*now+1] )%MOD;
	else return t[now] = ( t[2*now] * update(targetIdx, v, 2 * now + 1, (a + b) / 2 + 1, b) )%MOD;
}

long long print(int start, int end, int a, int b, int now) {
	if (b < a || a < start || end < b) return 1;
	if (start == a && end == b) return t[now];

	int mid = (start + end) / 2;

	int first = a, second = b;
	if (a <= mid &&  mid < b) {
		first = mid + 1;
		second = mid;
	}
	return ( print(start, mid, a, second, 2 * now) * print(mid + 1, end, first, b, 2 * now + 1) )%MOD;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	tree(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		switch (a) {
			case 1:
				update(b, c, 1, 1, n);
				break;
			case 2 :
				printf("%lld\n", print(1, n, b, c, 1)%MOD);
				break;
		}
	}
}