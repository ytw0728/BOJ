#include <stdio.h>
int main() {
	char c;
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%c ", &c);
			if (c == 'F')
				if (!((i + j) % 2)) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}