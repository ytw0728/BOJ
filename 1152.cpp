#include <stdio.h>

int main() {
	
	int cnt = 0;

	int space = 1;
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (c == ' ' && !space) space = 1;
		else if (c != ' ' && space) {
			space = 0;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}