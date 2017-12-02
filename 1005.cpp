// bfs �δ� Ǯ �� ����. ������ �����Ǵ� �ǹ����� Ÿ�� �ö� �� ���� ������ �ǹ��� �������� max ���� ���س��� �ȴ�.
#include <stdio.h>
#include <deque>

using namespace std;

int time[1001];
int data_[1001][1001];

int winning;
deque<int> q;

int bfs(int now) {
	if (q.back() == winning) return 0;
	
	q.push_back(now);
	for (int i = 1; i <= numB; i++) {
		if (data_[q.front()][i]) bfs(q.front());
	}
}

int numB, numR;
int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &numB, &numR);
		for (int j = 1; j <= numB; j++) {
			scanf("%d", &time[j]);
		}

		for (int j = 1; j <= numR; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			data_[a][b] = data_[b][a] = 1;
		}
		scanf("%d", &winning);

		bfs(1);
		for (int j = 1; j <= numB; j++) {
			time[j] = 0;
		}

		for (int p = 1; p <= numR; p++) {
			for (int q = 1; q <= numR; q++) {
				data_[p][q] = 0;
			}
		}
	}
	return 0;
}