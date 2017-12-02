#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stack;
vector<string> str;

int main() {
	int n; scanf("%d", &n);
	int t = n;
	str.resize(n);

	while (t--) cin >> str[t];

	int cnt = 0;
	for (auto i = str.begin(); i != str.end(); i++) {
		stack.clear();
		for (auto tmp = (*i).begin(); tmp != (*i).end(); tmp++) {
			if (stack.empty() || stack.back() != (*tmp)) stack.push_back(*tmp);
			else stack.pop_back();
		}
		if (stack.empty() ) cnt++;
	}

	printf("%d", cnt);
	return 0;
}