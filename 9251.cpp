#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS[1005][1005];

string str1, str2, tmp;
int main() {
	cin >> str1 >> str2;
	
	int cnt = 0;
	int len1 = str1.length(), len2 = str2.length();


	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else {
				LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
			}
		}
	}


	printf("%d\n", LCS[len1][len2]);

	return 0;
}