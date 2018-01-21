#include <stdio.h>



int main() {
	int t;
	scanf("%d\n", &t);

	int num = 0;
	
	while (t--) {
		char c;
		char last = '\0';	
		int cnt = 0;
		int done = 0;
		
		int arr[30] = { 0, };

		while ( (c = getchar()) != '\n' && c != EOF) {
			if (done || last == c) continue;
			else if( last != '\0' && arr[c-'a'] ){
				done = 1;
			}
			arr[c - 'a'] = 1;
			last = c;
		}

		if (!done) num++;

	}

	printf("%d\n", num);
	return 0;
}