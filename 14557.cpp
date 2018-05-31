#include <cstdio>

using namespace std;

int main() {
	int R, C;
	scanf("%d %d", &R, &C);

	int cards = R * C;
	int min = cards / 2; // 카드 종류만큼
	
	int max = 0;
	max = ( ( (min > 2) ? (min - 2) * 4 : 0)  + ( (min >= 2) ? 2 : 1) * 3) / 2; 
	// ( ( 카드 종류 - 2 ) * 4 + ( 맨처음 종류 + 맨마지막 종류 ) * 3 ) / 2
	// 1 종류 일땐 3/2  == 1이므로 처리가능.


	printf("%d %d", min, max);

	return 0;
}