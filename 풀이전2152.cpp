#include <cstdio>
#include <vector>

using namespace std;

vector<int> map[100005];


int main() {
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}



	return 0;
}