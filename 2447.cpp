#include <stdio.h>

char data[6562][6562];
void setting(int x, int y, int size) {
	if (size == 1) {
		data[x][y] = '*';
		return;
	}
	for (int i = 0; i <3; i++) {
		for (int j = 0;j < 3; j++) {
			if (i == 1 && j == 1) continue;
			setting(x + (size/3) * i ,y + (size/3)*j ,size/3 );
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);

	setting(1,1,n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if( data[i][j])	printf("%c", data[i][j]);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}