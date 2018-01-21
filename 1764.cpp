#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
#include <functional>


using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	priority_queue<string> nHeard;
	priority_queue<string> nSeen;
	priority_queue<string , vector<string>, greater<string> > result;

	while (n--) {
		string tmp;
		cin >> tmp;
		nHeard.push(tmp);
	}
	while (m--) {
		string tmp;
		cin >> tmp;
		nSeen.push(tmp);
	}

	while (!nHeard.empty() && !nSeen.empty()) {
		if (nHeard.top() == nSeen.top() ){
			result.push(nHeard.top());
			nHeard.pop();
			nSeen.pop();
		}
		else if (nHeard.top() > nSeen.top()) nHeard.pop();
		else nSeen.pop();
	}

	cout << result.size() << endl;
	while (!result.empty()) {
		cout << result.top() << endl;
		result.pop();
	}
	return 0;
}