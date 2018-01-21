#include <stdio.h>
#include <deque>

using namespace std;

deque<int> arr;
int origin[4];
int check[10001];

void rotate() {
	arr.push_back(arr.front());
	arr.pop_front();
}

int main() {
	
	for (int i = 0; i < 4; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
		origin[i] = tmp;
	}


	int min = 987654321;
	for (int i = 0; i < 4; i++) {
		int num = 0;
		for (auto n = arr.begin(); n != arr.end(); n++) {
			num *= 10;
			num += (*n);
		}
		if (min > num) min = num;
		rotate();
	}


	int a, b, c, d;
	a = b = c = d = 1;

	for (a=1; a <= 9; a++) {
		for (b=1; b <= 9; b++) {
			for (c=1; c <= 9; c++) {
				for (d=1; d <= 9; d++) {
					arr.clear();
					arr.push_back(a);
					arr.push_back(b);
					arr.push_back(c);
					arr.push_back(d);


					int minT = 987654321;
					for (int i = 0; i < 4; i++) {
						int num = 0;
						for (auto n = arr.begin(); n != arr.end(); n++) {
							num *= 10;
							num += (*n);
						}
						if (minT > num) minT = num;
						rotate();
					}
					if (minT > min) break;
					check[minT] = 1;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 1111; i <= min; i++) {
		if (check[i]) cnt++;
	}

	printf("%d", cnt);
	return 0;
}