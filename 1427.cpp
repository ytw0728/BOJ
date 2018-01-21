#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char arr[12];

bool cmp(char a, char b) {
	return a > b;
}

int main() {

	scanf("%s", arr);

	sort(arr, arr + strlen(arr), cmp);

	printf("%s\n", arr);
}