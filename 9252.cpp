#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS[1005][1005];
string str1, str2;

int main() {

	cin >> str1 >> str2;

	int len1 = str1.length(), len2 = str2.length();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				if (LCS[i][j - 1] > LCS[i - 1][j]) {
					LCS[i][j] = LCS[i][j - 1];
				}
				else {
					LCS[i][j] = LCS[i - 1][j];
				}
			}
		}
	}

	int tmp, start;
	tmp = LCS[len1][len2];
	start = len2;
	string ansStr = "";
	for (int i = len1; i > 0; i--) {
		for (int j = start; j > 0; j--) {
			if (LCS[i][j] == tmp && LCS[i][j - 1] == tmp - 1 && LCS[i - 1][j - 1] == tmp - 1 && LCS[i - 1][j] == tmp - 1) {
				tmp--;
				ansStr = str1[i-1] + ansStr;
				start = j;
				break;
			}
		}
	}

	printf("%d\n", LCS[len1][len2]);
	cout << ansStr << endl;
	return 0;
}