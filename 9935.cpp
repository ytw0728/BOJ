#include <stdio.h>
#include <deque>
#include <string>
#include <iostream>

using namespace std;

deque<char> st;
deque<char> result;
string resultStr;

int main() {
	string str;
	cin >> str;
	
	string exp;
	cin >> exp;

	int strLen = str.length();
	int expLen = exp.length();
	int i = 0;
	int expIdx = 0;
	int exactCnt = 0;
	int cnt = 0;

	for (auto c = str.begin(); c != str.end(); c++) st.push_back(*c);

	while( !st.empty() ){
		if ( st.front() == exp[expIdx]) {
			expIdx++;
			cnt++;
			exactCnt++;
		}
		else{
			expIdx = 0;
			if ( st.front() == exp[expIdx]) {
				expIdx++;
				exactCnt = 1;
			}
			else {
				cnt = 0;
				exactCnt = 0;
				expIdx = 0;
			}
		}
		if (exactCnt == expLen) {
			result.push_back(st.front());
			st.pop_front();

			int tmp = exactCnt;
			while (tmp--) {
				result.pop_back();
			}

			tmp = expLen;
			while ( !result.empty() && tmp--){
				st.push_front(result.back());
				result.pop_back();
			}
			cnt = 0;
			exactCnt = 0;
			expIdx = 0;
		}
		else {
			result.push_back(st.front());
			st.pop_front();
		}
	}

	while (!st.empty()) {
		result.push_back(st.front());
		st.pop_front();
	}

	while (!result.empty()) {
		resultStr.push_back(result.front());
		result.pop_front();
	}

	if ( resultStr.empty()) printf("FRULA");
	else printf("%s", resultStr.c_str());

	return 0;
}