#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define HEAP_SIZE 256

typedef int Data;
Data heap[HEAP_SIZE];
int hcnt = 0;

// 두수를 바꾸는 함수
void swap(Data* a, Data* b);
// 힙에 데이터를 넣는다.
void putHeap(Data data);
// 힙에서 데이터를 가져온다. (힙에서 맨 위에 데이터를 가져오고 삭제한다.)
Data getHeap();
// 배열의 내용을 순서대로 출력해준다.
void printArray();

int main() {
	Data input, result;

	printf("힙에 삽입할 데이터를 입력하세요 : ");
	scanf_s("%d", &input);


	while (input > 0) {
		putHeap(input);
		printf("힙에 삽입할 데이터를 입력하세요 : ");
		scanf_s("%d", &input);
	}

	// 배열값 출력해보기
	printf("\n");
	printArray();
	printf("\n");

	// 힙에서 값 꺼내기
	printf("\n%d : ", getHeap());
	printArray();
	printf("\n%d : ", getHeap());
	printArray();
	printf("\n%d : ", getHeap());
	printArray();

	return 0;
}

void swap(Data* a, Data* b) {
	Data tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void putHeap(Data data) {
	int i = 0;
	heap[++hcnt] = data;
	i = hcnt;
	while ((i != 1) && (heap[i] > heap[i / 2])) {
		// i번째 노드와 부모 노드를 교환환다.
		swap(&heap[i], &heap[i / 2]);
		// 한 레벨 위로 올라단다.
		i /= 2;
	}
	heap[i] = data; // 새로운 노드를 삽입
	printArray();
	printf("\n");
}

Data getHeap() {
	// 첫번째 값 꺼내기 
	Data result = heap[1];

	// 마지막값을 첫번째에 넣기
	heap[1] = heap[hcnt];
	hcnt--;

	// 아래와 비교하면서 하나씩 내려가면서 알맞은 위치 찾기
	int parent, child;

	parent = 1;
	while (1) {
		child = parent * 2;
		if (child > hcnt) break;
		else if (child < hcnt)
			child = (heap[child] > heap[child + 1]) ? child : child + 1;

		if (heap[parent] >= heap[child]) break;
		else
			swap(&heap[parent], &heap[child]);
		parent = child;
	}

	return result;
}

void printArray() {
	for (int i = 1; i <= hcnt; i++) {
		printf(" %d |", heap[i]);
	}
}