// sort  cmp 함수에서 맨처음에 <= 를 쓰면 invalid comparator 로 에러남
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;


int n;
typedef struct grade {
	int point;
	int sum = 0;
	int voteCnt = 0;
}grade;

grade arr[400];

bool cmp0( grade a , grade b) {
	if( a.sum > b.sum ) return true;

	if( a.sum == b.sum ) {
		if (a.voteCnt > b.voteCnt) return true;
	}
	return false;
}

bool cmp1(grade a, grade b) {
	if (a.point < b.point) return true;
	return false;
}


int cntV = 1;
int is_at[1000001];

int main() {

	scanf("%d", &n);

	while (n != 0) {
		cntV = 1;
		for (int i = 0; i < n; i++) {
			int nums;
			scanf("%d", &nums);
			int multi = 1000;
			for (int j = 0; j < nums; j++) {
				int temp;
				scanf("%d", &temp);
				if (is_at[temp] == 0) is_at[temp] = cntV++;
				arr[is_at[temp]].point = temp;
				arr[is_at[temp]].sum += 3 - j;
				if (j != 2) {
					arr[is_at[temp]].voteCnt += multi;
					multi /= 1000;
				}
			}
		}
		
		sort(arr + 1, arr + 301, cmp0);

		int cnt = 1;
		for (int i = 2; i < 301 ; i++) {
			if (arr[i].sum == arr[i - 1].sum) {
				if (arr[i].voteCnt == arr[i - 1].voteCnt) {
						cnt++;
				}
				else {
					break;
				}
			}
			else break;
		}

		sort(arr + 1, arr + cnt+1, cmp1);


		for (int i = 1; i <= cnt; i++) {
			printf("%d ", arr[i].point);
		}
		printf("\n");

		for (int i = 1; i < 301; i++) {
			arr[i].sum = 0;
			arr[i].voteCnt = 0;
			arr[i].point = 0;
		}
		memset(is_at, 0, sizeof(int) * 1000001);

		scanf("%d", &n);
	}
	return 0;
}
