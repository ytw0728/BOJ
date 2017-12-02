// 창용이의 시계
#pragma warning (disable: 4996)
#include <stdio.h>


int hour, min, sec;
int changeTime(bool b) {
	int time; scanf("%d", &time);

	long long tempTime = hour * 60 * 60 + min * 60 + sec;
	if (b) { // 앞
		tempTime += time;
		while( tempTime >= ( 24 * 60 * 60 ) ){
			tempTime -= 24 * 60 * 60;
		}
	}
	else {
		tempTime -= time;
		while(tempTime < 0){
			tempTime += 24 * 60 * 60;
		}
	}
	hour = (int)(tempTime / (60 * 60));
	tempTime %= (60 * 60);

	min = (int)(tempTime / 60);
	tempTime %= 60;

	sec = (int)tempTime;
	return 0;
}
int print(void) {
	printf("%d %d %d\n", hour, min, sec);
	return 0;
}

int main() {
	
	scanf("%d %d %d", &hour, &min, &sec);
	int testCase; scanf("%d", &testCase);

	int query;

	for (int i = 0; i < testCase; i++) {
		scanf("%d", &query);
		switch (query) {
			case 1: changeTime(true); break;
			case 2: changeTime(false); break;
			case 3: print(); break;
		}

	}
}