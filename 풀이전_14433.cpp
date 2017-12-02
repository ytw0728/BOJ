// 한조 대기중  //아직
/*
	반례
	1 : 1, 5, 6, 7
	2 : 1, 2
	3: 5
	4 :6
	5 :7
	최대 매칭 불가능

	그냥 매칭 알고리즘을 쓰자
*/

#pragma warning (disable: 4996)
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> ourArray[300], yourArray[300];

// 

int dataIndex = 0;
bool search( int* arr , int test) {
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i] == test) return false;
	}
	arr[dataIndex++] = test;
	return true;
}

int check(vector<int>* arr, int n) {
	int* already = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) already[i] = 0;

//	printf("\n\n\ntest__ \n");//

	int countOfTrolls = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)arr[i].size(); j++) {
//			printf("%d, ", arr[i].back());//
			if( search(already, arr[i].back() )){
//				printf(": %d ", arr[i].size());//
				countOfTrolls++;
				break;
			}
			arr[i].pop_back();
//			if (j == (int)arr[i].size() - 1) printf(": %d ", arr[i].size());//
		}
		
//		printf("\n");//
	}
//	printf("\n\n");//
	return countOfTrolls;
}
int sort(vector<int>* arr, int n){
	int temp;
	
	for (int i = 1; i <= n; i++) {
		temp = arr[i].size();
		vector<int> tempArr;
		for (int j = i; j <= n; j++){
			if ( (int)arr[j].size() < temp) {
				tempArr = arr[i];
				arr[i] = arr[j];
				arr[j] = tempArr;
				break;
			}
		}
	}
//	printf("\n sorted \n");//
//	for (int i = 0; i <= n; i++) printf("%d, ", arr[i].size());//
	return 0;
}

int main(){
	int numPlayer, numTroll, ourTrolls, yourTrolls;
	
	
	scanf("%d %d %d %d", &numPlayer, &numTroll, &ourTrolls, &yourTrolls);

	int player, want;
	int ourWannaPlayer = 0, yourWannaPlayer = 0;
	for (int i = 0; i < ourTrolls; i++) {
		scanf("%d %d", &player, &want);
		if (ourWannaPlayer < player) ourWannaPlayer = player;
		ourArray[player].insert(ourArray[player].begin(),want);
	}
	for (int i = 0; i < yourTrolls; i++) {
		scanf("%d %d", &player, &want);
		if (yourWannaPlayer < player) yourWannaPlayer = player;
		yourArray[player].insert(yourArray[player].begin(),want);
	}

	sort( ourArray, ourWannaPlayer );
	int numOur = check(ourArray, ourWannaPlayer);
	
	dataIndex = 0;

	sort( yourArray, yourWannaPlayer );
	int numYour = check(yourArray, yourWannaPlayer);

//	printf("\n\n %d %d \n\n", numOur, numYour);//
	if (numOur >= numYour) printf("그만 알아보자");
	else printf("네 다음 힐딱이");
	return 0;
}