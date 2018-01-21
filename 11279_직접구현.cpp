#include <stdio.h>
#define MAXSIZE 100000

typedef struct Heap {
	int size;
	int heap[MAXSIZE];

	Heap() {
		size = 0;
	}
	
	void swap(int *a, int *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	};
	int push(int v) {

		if (size + 1 > MAXSIZE) {
			return 0;
		}

		heap[size] = v;
		int last = size;
		int	parent = (size - 1) / 2;

		while (last > 0 && heap[last] > heap[parent]) {
			swap(&heap[last], &heap[parent]);
			last = parent;
			parent = (parent - 1) / 2;
		}
		size++;
	};
	int pop() {
		if (size <= 0) return 0;

		int ret = heap[0];

		heap[0] = heap[size];
		

		int last = 0;
		int left = last * 2 + 1;
		int right = last * 2 + 1;

		int maxNode = last;

		while (left < size) {
			if (heap[maxNode] < heap[left]) maxNode = left;
			if (right < size && heap[maxNode] < heap[right]) maxNode = right;

			if (maxNode == last) break;
			else {
				swap(&heap[last], &heap[maxNode]);
				last = maxNode;
				left = last * 2 + 1;
				right = last * 2 + 2;
			}
		}
		size--;
		return ret;
	};
	void print() {
		printf("Ãâ·Â : %d\n", pop());
	};
}Heap;

Heap PQ = Heap();
int main() {
	int t;
	scanf("%d", &t);


	while (t--) {
		int tmp;
		scanf("%d", &tmp);
		
		switch (tmp) {
			case 0: PQ.print(); break;
			default: PQ.push(tmp); break;
		}

	}


	return 0;
}