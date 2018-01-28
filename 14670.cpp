#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map<int, int> medicine;

int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		medicine[a] = b;
	}

	int r;
	scanf("%d", &r);

	while (r--) {
		int l;
		scanf("%d", &l);
		int ok = 1;
		vector<int> result;
		while (l-- ) {
			int tmp;
			scanf("%d", &tmp);
			if (medicine.count(tmp) == 0) ok = 0;
			else result.push_back(medicine[tmp]);
		}

		if (ok) {
			for (auto i = result.begin(); i != result.end(); i++) {
				printf("%d ", *i);
			}
		}
		else printf("YOU DIED");

		printf("\n");
	}
	return 0;
}