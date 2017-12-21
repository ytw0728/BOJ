#include <stdio.h>
#include <vector>
#include <queue>


using namespace std;

vector<priority_queue<int> > status; // ���� ����, �����ִ� ���� ��

int cnt = 0;

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	
	status.resize(6 + 1); // ��Ÿ�� ���� 6��

	for (int i = 1; i <= 6; i++) status[i].push(0);
	
	int cnt = 0;
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		while (status[a].top() > b) {
			status[a].pop();
			cnt++;
		}
		if (status[a].top() != b) {
			status[a].push(b);
			cnt++;
		}
	}

	printf("%d\n", cnt);
	
	return 0;
}