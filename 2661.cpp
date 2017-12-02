#include <iostream>
#include <string>

using namespace std;

int n;
string result = "";
bool done = 0;

void dfs(int data) {
	if (done) return;
	result += (data + '0');

	int width = result.length() / 2;

	for (int i = 2; i <= width; i++) {
		string temp1 = result.substr(result.length() - i,i);
		string temp2 = result.substr(result.length() - i*2, i);
		if (temp1 == temp2) {
			result.erase(result.length() - 1);
			return;
		}
	}

	if (result.length() == n) {
		cout << result << endl;
		done = true;
		return;
	}
	if (data == 1) {
		dfs(2);
		dfs(3);
		result.erase(result.length() - 1);
	}
	if (data == 2) {
		dfs(1);
		dfs(3);
		result.erase(result.length() - 1);

	}
	if (data == 3) {
		dfs(1);
		dfs(2);
		result.erase(result.length() - 1);

	}
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}