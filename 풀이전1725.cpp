#include <stdio.h>
#include <vector>

using namespace std;

vector<int> st;
int S[100001];

int main() {

	int n;
	scanf("%d", &n);

	int num = 1;
	int tmpN = n;

	while (tmpN--) {
		int t;
		scanf("%d", &t);

		if (st.back() > t) {
			if (num > 1) num--; 
		}
		else {
			num++;
		}
		
		st.push_back(t);
	}

	int maxSize = 0;
	
	for (int i = 0; i < n; i++) {
		int t;
		maxSize = ( maxSize < (t = S[i] * st[i]) )? t : maxSize;
	}

	printf("%d\n", maxSize);
	
	return 0;
}