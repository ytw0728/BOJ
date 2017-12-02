#include <stdio.h>
#include <vector>

using namespace std;
vector<int> arr;
int n;

void find() {
	for (auto i = arr.begin(); i != arr.end(); i++) {
		bool binary[8];
		int index = 0;
		while (index < 8 ) {
			if (*i > 0) {
				binary[index++] = *i % 2; // reverse binary
				*i /= 2;
			}
			else {
				binary[index++] = 0;
			}
		}

		bool fi1[8], fi2[8]; // fi1 is left-shifted data
		fi1[0] = 0;
		index = 0;
		while (index < 8) {
			if (binary[index]) {
				fi2[index] = fi1[index] == 0 ? 1: 0;
			}
			else {
				fi2[index] = fi1[index] == 0 ? 0 : 1;
			}
			index++;
			if( index < 8) fi1[index] = fi2[index-1];
		}

		index = 0;
		int bin = 1;
		int result = 0;
		while (index < 8) {
			result += bin * fi2[index++];
			bin *= 2;
		}
		printf("%d ", result);
	}
}
int main() {
	scanf("%d", &n);

	int tempN = n;

	while (tempN--) {
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}

	find();
	return 0;
}