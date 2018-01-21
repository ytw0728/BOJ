#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string leftSt;
string rightSt;

void left() {
	if (leftSt.empty() ) return;

	rightSt.push_back(leftSt.back());
	leftSt.pop_back();
	
}
void right() {
	if (rightSt.empty() ) return;

	leftSt.push_back(rightSt.back());
	rightSt.pop_back();
}
void del(){
	if (leftSt.empty()) return;

	leftSt.pop_back();
}
void insert(char c) {
	leftSt.push_back(c);
}

int main() {
	
	cin >> leftSt;

	int n;
	scanf("%d\n", &n);

	char term;
	char c;

	while (n--) {
		cin >> term;
		if (term == 'P') cin >> c;

		switch (term) {
			case 'L': left(); break;
			case 'D': right(); break;
			case 'B': del(); break;
			case 'P': insert(c); break;
		}
	}

	reverse(rightSt.begin(), rightSt.end());
	cout << leftSt << rightSt;
	

	return 0;
}