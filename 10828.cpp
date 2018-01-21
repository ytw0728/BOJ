#include <stdio.h>
#include <string.h>
int idx = -1;
int arr[10001];
int pop() {
	if (idx == -1) return -1;
	return arr[idx--];
}
void push(int v) {
	arr[++idx] = v;
}
int size() {
	return idx + 1;
}
int empty() {
	return idx == -1;
}
int top() {
	if (idx == -1) return -1;
	return arr[idx];
}

int main() {
	int n;
	scanf("%d", &n);

	char terms[100];
	while (n--) {
		scanf("%s", terms);
		if (!strcmp(terms, "push") ){
			int v;
			scanf("%d", &v);
			push(v);
		}
		else if (!strcmp(terms, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(terms, "empty")) {
			printf("%d\n", empty() );
		}
		else if (!strcmp(terms, "top")) {
			printf("%d\n", top());
		}
		else if (!strcmp(terms, "size")) {
			printf("%d\n", size());
		}
	}
	return 0;
}