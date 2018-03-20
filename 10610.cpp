#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char arr[100001];

bool cmp(char a, char b) {
	return a > b;
}
int main(){
	
	scanf("%s", arr); // 0 && %3 != 3  => -1 

	int len = strlen(arr);
	bool zero = 0;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == '0') zero = 1;
		else (sum += (arr[i] - '0')) %= 3;
	}

	sort(arr, arr + len , cmp );

	if( zero && sum == 0 ) printf("%s\n", arr);
	else printf("-1\n");
	
	return 0;
}