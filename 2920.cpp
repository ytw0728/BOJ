#include <stdio.h>

int main() {
	int arr[8];
	int type = -1; // 0 : ascending, 1 : descending, 2 : mixed , -1 : unset
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &arr[i-1]);
		if ( ( type == 0 || type == -1 ) && arr[i - 1] == i) type = 0;
		else if ( ( type == 1 || type == -1 ) && arr[i - 1] == 9 - i) type = 1;
		else type = 2;
	}


	switch (type) {
	case 0: 
		printf("ascending\n");
		break;
	case 1: 
		printf("descending\n");
		break;
	case 2: 
		printf("mixed\n");
		break;
	}
	
	return 0;
} 