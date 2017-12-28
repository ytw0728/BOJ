#include <stdio.h>
#include <cstring>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

int main(void) {
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int direction = 0;  // 0 ¾Õ , 1 µÚ

		string command;
		cin >> command;

		int len;
		scanf("%d", &len);

		deque<int> arr;

		
		while (getchar() != '\n') ;

		string tmp;
		cin >> tmp;
		tmp.erase(tmp.end()-1, tmp.end());
		tmp.erase(tmp.begin(), tmp.begin()+1);

		char* ptr = NULL;
		ptr = strtok( (char*)tmp.c_str(), "," );
		while (ptr != NULL) {
			arr.push_back(atoi(ptr));
			ptr = strtok(NULL, ",");	
		}

		int done = 0;
		for (auto i = command.begin(); i != command.end(); i++) {
			switch (*i) {
				case 'R': direction = !direction; break;
				case 'D': 
					if (arr.empty()){
						done = 1;
						break;
					}
					else {
						if (direction) arr.pop_back();
						else arr.pop_front();
					}
			}
		}

		if (done) {
			printf("error\n");
			continue;
		}
		
		printf("[");
		if (!arr.empty()) {
			auto start = arr.begin();
			auto end = arr.end() - 1;
			int add = 1;

			if (direction) {
				start = arr.end() - 1;
				end = arr.begin();
				add = -1;
			}

			for (;; start += add) {
				printf("%d", *start);
				if (start == end) break;
				printf(",");
			}
		}
		printf("]\n");
	}


	return 0;
}