#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


int main() {

	int n;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);

		int done = 0;

		for (int i = 2; !done && i <= 64; i++) {
			string str;
			int tmp = num;

			while (tmp > 0) {
				str.push_back( (tmp % (i)) + '0');
				tmp /= (i);
			}

			auto end = str.end()-1;
			end -= str.length() / 2;
			auto j = str.end() - 1;

			int strDone = 1;
			for (auto i = str.begin(); i != end + 1; i++, j--) {
				if (*i != *j) {
					strDone = 0;  break;
				}
			}
			if (strDone) done = 1;
		}
		cout << done << endl;
	}

	return 0;
}