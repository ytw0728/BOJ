#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int n, m;
int s, t;

vector<int> route[10001];
vector<int> rev[10001];
vector<int> finish;

bool chk[10001];
int cnt = -1;
bool flagS, flagT;

void rev_travel(int p) {
	if (p == s) flagS = true;
	if (p == t) flagT = true;
	
	chk[p] = true;
	for (auto i : rev[p]) {
		if (!chk[i]) rev_travel(i);
	}
	cnt++;
}

void travel(int p) {
	chk[p] = true;
	for (auto i : route[p]) {
		if ( !chk[i] ) travel(i);
	}
	finish.push_back( p );
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		route[a].push_back(b);
		rev[b].push_back(a);
	}

	route[t].push_back(s);
	rev[s].push_back(t);

	for (int i = 1; i <= n; i++) {
		if ( !chk[i] ) {
			travel(i);
		}
	}
	
	memset(chk, 0, n + 1);

	int result = 0;
	while ( !finish.empty() ) {
		flagS = flagT = false;
		cnt = 0;
		if (!chk[finish.back()]) {
			rev_travel(finish.back());
			if (flagS && flagT && cnt != 1 ) {
				printf("%d", cnt);
				return 0;
			}
		}
		finish.pop_back();
	}
	printf("0");
	
	return 0;
}