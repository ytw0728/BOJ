#include <string>
#include <iostream>
using namespace std;

int num;
void length(int level, int past_length, int now_length) {
	if (level == 0 && num <= 3) {
		if (num == 1) printf("m");
		else printf("o");
		return;
	}
	if (num <= past_length) {
		length(level - 1, (past_length - (level-1 + 3)) / 2 , (now_length - (level+3)) / 2 );
	}
	else if (past_length < num && num <= now_length - past_length) {
		num -= past_length;
		if (num == 1) printf("m");
		else printf("o");
		return; 
	}
	else {
		num -= (past_length + level + 3);
		length(level - 1, (past_length - (level - 1 + 3)) / 2, (now_length - (level + 3)) / 2);
	}


}
int main() {
	cin >> num;

	int level = 0;
	int last_length = 0;
	int t = 3;
	while (t <= num) {
		last_length = t;
		t = 2 * t + (level+1) + 3;
		level++;
	}

	length(level, last_length, t);

	return 0;
}