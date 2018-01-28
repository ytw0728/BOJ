#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int woods[1000000];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &woods[i]);
	}
		

	sort(woods, woods + n, cmp);

	int idx = 0;
	int nextIdx = 1;
	int h = woods[0];
	int num = 1;
	
	while ( m > 0 ) {
		if (woods[idx] - m/num < woods[nextIdx]) {
			h = woods[nextIdx];
			m -= (woods[idx]-h) * num;
			num++;
			idx++;
			nextIdx++;
			while ( woods[idx] == woods[nextIdx]) {
				num++;
				idx++;
				nextIdx++;
			}
		}
		else if (m / num == 0) {
			h--;
			m -= num;
		}
		else if (woods[idx] - m/num >= 0 && woods[idx] - m/num >= woods[nextIdx]) {
			h -= m / num;
			m -= (woods[idx] - h) * num;
		}
		else {
			h--;
			m -= num;
		}
	}

	printf("%d\n", h);

	return 0;
}