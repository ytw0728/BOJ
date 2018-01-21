#include <stdio.h>
#include <vector>

using namespace std;
vector<char> st;

int main() {
	char c;
	int cnt = 0;
	int lazer = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (c == '(') {
			st.push_back(c);
			lazer = 1;
		}
		else if (c == ')') {
			if ( lazer ){
				st.pop_back();
				cnt += st.size();
				lazer = 0;
			}
			else {
				cnt++;
				st.pop_back();
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}