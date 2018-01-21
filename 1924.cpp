#include <stdio.h>

int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31 ,31, 30, 31, 30, 31 };
char* wDay[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {

	int m, n;
	scanf("%d %d", &m, &n);
	int days = 0;
	

	for (int i = 0; i < m; i++) days += arr[i];
	days += n;

	int day = days % 7;

	printf("%s\n", wDay[day]);

	return 0;
}