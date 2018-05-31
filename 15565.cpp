#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<int> st;
vector<int> answers;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	int tmp;
	int cnt = 0;
	int startIdx = 0;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		switch (tmp) {
			case 1:
				cnt++;
				if (!startIdx || k == 1) startIdx = i;
				else st.push(i);

				if (cnt >= k) {
					answers.push_back(i - startIdx + 1);
					if (k != 1) {
						startIdx = st.front();
						st.pop();
					}
				}
				break;
			case 2:
				break;
		}
		
	}
	
	sort(answers.begin(), answers.end());
	
	if (answers.size() == 0) printf("-1\n");
	else printf("%d\n", answers[0]);
	return 0;
}