#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

map<string, int > arr;


int main() {
	arr.insert(map<string, int >::value_type("black", 0));
	arr.insert(map<string, int >::value_type("brown", 1));
	arr.insert(map<string, int >::value_type("red", 2));
	arr.insert(map<string, int >::value_type("orange", 3));
	arr.insert(map<string, int >::value_type("yellow", 4));
	arr.insert(map<string, int >::value_type("green", 5));
	arr.insert(map<string,int >::value_type("blue", 6));
	arr.insert(map<string,int >::value_type("violet", 7));
	arr.insert(map<string, int >::value_type("grey", 8));
	arr.insert(map<string, int >::value_type("white", 9));


	long long v = 0;
	for (int i = 0; i < 3; i++) {
		string tmp;
		cin >> tmp;
			
		if( i < 2){
			v += arr[tmp] * pow(10, 1-i);
		}
		else {
			v *= pow(10, arr[tmp]);
		}

	}	

	cout << v << endl;

	return 0;
}