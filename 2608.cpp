#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

map<char, int> arr;
map<int, string> rev;
int nums[13] = { 1,5,10,50,100,500,1000,4,9,40,90,400,900 };

int main() {
	arr.insert(map<char, int>::value_type('I', 1));
	arr.insert(map<char, int>::value_type('V', 5));
	arr.insert(map<char, int>::value_type('X', 10));
	arr.insert(map<char, int>::value_type('L', 50));
	arr.insert(map<char, int>::value_type('C', 100));
	arr.insert(map<char, int>::value_type('D', 500));
	arr.insert(map<char, int>::value_type('M', 1000));

	rev.insert(map<int, string>::value_type(1,"I"));
	rev.insert(map<int, string>::value_type(5,"V"));
	rev.insert(map<int, string>::value_type(10,"X"));
	rev.insert(map<int, string>::value_type(50,"L"));
	rev.insert(map<int, string>::value_type(100,"C"));
	rev.insert(map<int, string>::value_type(500,"D"));
	rev.insert(map<int, string>::value_type(1000, "M"));
	rev.insert(map<int, string>::value_type(4, "IV"));
	rev.insert(map<int, string>::value_type(9, "IX"));
	rev.insert(map<int, string>::value_type(40, "XL"));
	rev.insert(map<int, string>::value_type(90, "XC"));
	rev.insert(map<int, string>::value_type(400, "CD"));
	rev.insert(map<int, string>::value_type(900,"CM"));

	int num = 0;

	for (int i = 0; i < 2; i++) {
		string str;
		cin >> str;

		int last = 0;
		for (auto i = str.begin(); i != str.end(); i++) {
			if (last < arr[*i]) num += arr[*i] - last*2;
			else num += arr[*i];
			last = arr[*i];
		}
	}


	printf("%d\n", num);


	int result = 0;
	string resultStr;

	
	while (num != result) {

		int idx = -1;
		int min = 987654321;
		int i;
		for ( i = 0; i < 13; i++) {
			if (num - (result+nums[i] ) >= 0 && num - (result + nums[i]) < min) {
				min = num - (result + nums[i]);
				idx = i;
			}
		}

		result += nums[idx];
		cout << rev[nums[idx]];
	}


	return 0;
}