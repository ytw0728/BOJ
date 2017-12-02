#include <stdio.h>
#include <stack>
#include <algorithm>
#define ll long long
#define MAX 100000 + 10
using namespace std;
ll n, arr[MAX];

ll histogram() {
	stack< ll> st;
	ll i, ret = 0;

	st.push(-1);

	for (i = 0; i < n; i++) {
		while (!st.empty() && arr[i] < arr[st.top()]) {
			int tmp = st.top(); st.pop();
			if (!st.empty())
				ret = max(ret, arr[tmp] * (i - st.top() - 1));
		}
		st.push(i);
	}

	while (!st.empty()){
		int tmp = st.top(); st.pop();
		if(!st.empty())
			ret = max(ret, arr[tmp] * (i - st.top() - 1) );
	}

	return ret;
}
int main() {
	scanf("%lld", &n);
	while (n != 0) {
		for (ll i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}

		printf("%lld\n", histogram());
		scanf("%lld", &n);
	}
	return 0;
}