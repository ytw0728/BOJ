#include <stdio.h>
#include <queue>

using namespace std;

queue< int > q;


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) q.push(i);
	
	int last;
	int which = 0;
	while (!q.empty()) {
		last = q.front();

		if (which) q.push(q.front());
		q.pop();

		which = !which;
	}

	printf("%d\n", last);

	return 0;
}