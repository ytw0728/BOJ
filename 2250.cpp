#pragma warning (disable: 4996 )
#include <stdio.h>

int data[10001][10001];
int depth_width[10001] = { 0, };
int chk[10001];
int depth = 0;

int max_depth = 0;

int num;
int dfs(int n) {
	int now = depth;
	chk[n] = 1;
	if (max_depth < depth) max_depth = depth;

	int no_child = 1;
	int child = 0;
	for (int i = 1; i <= num; i++) {
		if (data[n][i] && !chk[i]) {
			if( depth == now ) depth++;
			child += dfs(i);
			no_child = 0;
		}
	}
	depth--;
	depth_width[now] += child;

	if (no_child == 1) {
		return 1;
	}
	else {
		return child;
	}

}
int main() {
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			data[i][j] = 0;
		}
	}
	int temp, child1, child2;
	int first;
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		if (i == 0) first = temp;
		scanf("%d %d", &child1, &child2);
		if (child1 != -1) data[child1][temp] = data[temp][child1] = 1;
		if (child2 != -1) data[child2][temp] = data[temp][child2] = 1;
	}

	for (int i = 0; i < num; i++) {
		chk[i] = 0;
	}
	
	dfs(first);

	int max_width = 0;
	int max_index = 0;
	int i;
	for (i = 0; i < max_depth; i++) {
		if (max_width < depth_width[i]) {
			max_width = depth_width[i];
			max_index = i;
		}
	}


	printf("%d %d", i+1, max_width);
	return 0;
}