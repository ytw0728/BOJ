#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string n; cin >> n;
	
	int x, y; x = y = 0;
	for (auto i = n.begin(); i != n.end(); i++) {
		x *= 2;
		y *= 2;
		int tempX, tempY;
		switch (*i) {
			case '0': tempX = tempY = 0; break;
			case '1': tempX = 1, tempY = 0; break;
			case '2': tempX = 0, tempY = 1; break;
			case '3': tempX = tempY = 1; break;
			default: break;
		}
		x += tempX;
		y += tempY;
	}
	printf("%d %d %d", n.length(), x,y);
	return 0;
}