#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dy[301][3];
int value[301];

int go(int p, int cnt) {
	if (p > n) return -987654321;
	if (p == n) return value[n];

	int& ret = dy[p][cnt];
	if (ret != 0) return ret;
	
	if (cnt < 2) ret = max( ret,go(p + 1, cnt + 1)+value[p]);
	ret = max(ret, go(p + 2, 1)+value[p]);

	return ret;
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &value[i]);
	}

	int result = go(0, 0);

	printf("%d", result);
	return 0;
}