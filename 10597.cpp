#include <stdio.h>
#include <string.h>
char num[92];
int chk[51], result[50];
int length;

int main() {
	scanf("%s", num);

	length = strlen(num) < 10 ? strlen(num) : 9+ (strlen(num)-9)/2;
	

	return 0;
}