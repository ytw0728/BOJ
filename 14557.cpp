#include <cstdio>

using namespace std;

int main() {
	int R, C;
	scanf("%d %d", &R, &C);

	int cards = R * C;
	int min = cards / 2; // ī�� ������ŭ
	
	int max = 0;
	max = ( ( (min > 2) ? (min - 2) * 4 : 0)  + ( (min >= 2) ? 2 : 1) * 3) / 2; 
	// ( ( ī�� ���� - 2 ) * 4 + ( ��ó�� ���� + �Ǹ����� ���� ) * 3 ) / 2
	// 1 ���� �϶� 3/2  == 1�̹Ƿ� ó������.


	printf("%d %d", min, max);

	return 0;
}