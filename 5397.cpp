/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string str;
		vector<char> buffer;
		int cursor = 0;

		cin >> str;

		for (auto i = str.begin(); i != str.end(); i++) {
			if (*i == '<') cursor > 0 ? cursor-- : 1 ;
			else if (*i == '>') cursor < buffer.size() ? cursor++ : 1;
			else if (*i == '-') cursor>0 ? buffer.erase( buffer.begin() + cursor-1 ), cursor-- : 1;
			else buffer.insert(buffer.begin() + cursor, *i), cursor++;
		}

		for (auto i = buffer.begin(); i != buffer.end(); i++) {
			cout << *i;
		}
		cout << endl;
	}

	return 0;
}
*/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string str;
		deque<char> left;
		deque<char> right;

		cin >> str;

		for (auto i = str.begin(); i != str.end(); i++) {
			if (*i == '<') !left.empty() ? right.push_front(left.back()), left.pop_back() : (void)1 ;
			else if (*i == '>') !right.empty() ? left.push_back(right.front()), right.pop_front() : (void)1;
			else if (*i == '-') !left.empty() ? left.pop_back() : (void)1;
			else left.push_back(*i);
		}

		for (auto i = left.begin(); i != left.end(); i++) {
			cout << *i;
		}		
		for (auto i = right.begin(); i != right.end(); i++) {
			cout << *i;
		}
		cout << endl;
	}

	return 0;
}