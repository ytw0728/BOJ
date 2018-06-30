#include <stdio.h>
#include <string.h>
int chk[30];
int main() {
	char s[105];
	scanf("%s", s);
	int idx = 0;
	memset(chk, -1, sizeof(chk));

	while (s[idx] != NULL) {
		if ( chk[s[idx] - 'a'] == -1 )
			chk[s[idx] - 'a'] = idx;
		idx++;
	}
	for (int i = 0; i <= 'z' - 'a'; i++) {
		printf("%d ", chk[i]);
	}
	return 0;
}