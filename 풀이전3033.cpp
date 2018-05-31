#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<char> window;
int length = 0;

int main() {
	string str;
	cin >> str;

	for (auto i = str.begin(); i != str.end(); i++) {


		window.push_back(*i);
	}

	return 0;
}