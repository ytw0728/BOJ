#include <stdio.h>
#include <string>
#include <vector>

int arr[30];

void input(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (c > 'Z') c -= 'a' - 'A';
		c -= 'A';

		arr[c]++;
	}
}
char find() {
	int maxIdx = -1;
	int v = -1;
	int done = 1;

	for (int i = 0; i <= 'Z' - 'A'; i++) {
		if (arr[i] > v) {
			v = arr[i];
			maxIdx = i;
			done = 1;
		}
		else if (arr[i] == v) done = 0;
	}

	if (done) return maxIdx;
	else return -1;
}
int main() {
	input();
	char result = find();

	if (result == -1) printf("?\n");
	else {
		printf("%c\n", 'A' + result);
	}
	return 0;
}