#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int square[51][51];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int max_size = n > m ? m : n;

	string temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		for (int j = m; j >= 1; j--) {
			square[i][j] = temp.back() - '0';
			temp.pop_back();
		}
	}

	int margin = 0;
	int maxArea = 0;
	bool find = false;
	while( margin+1 <= max_size ) {
		find = false;
		for (int i = 1; i + margin <= n; i++) {
			for (int j = 1; j + margin <= m; j++) {
				if (square[i][j] == square[i + margin][j] && square[i][j] == square[i][j+margin] && square[i][j] == square[i + margin][j+margin]){
					maxArea = margin+1;
					find = true;
					break;
				}
			}
			if (find) break;
		}
		margin++;
	}

	printf("%d", maxArea * maxArea);
	return 0;
}