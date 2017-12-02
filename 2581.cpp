#include <cstdio>
#include <deque>

using namespace std;
bool isprime( int a) {
	if (a == 1) return false;
	if (a == 2) return true;
	int until = a / 2;
	int i = 2;
	while (i <= until && a%i != 0) i++;

	if (i == until + 1)	return true;
	else return false;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	deque<int> arr;
	for (int i = a; i <= b; i++) {
		if (isprime(i)) arr.push_back(i);
	}

	int result = 0;

	for (auto i = arr.begin(); i != arr.end(); i++) {
		result += *i;
	}
	
	if (result != 0) {
		printf("%d\n", result);
		printf("%d", arr.front());
	}
	else {
		printf("-1");
	}
	return 0;
}