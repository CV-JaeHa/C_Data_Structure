#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define HEAP_SIZE 256

typedef int Data;
Data heap[HEAP_SIZE];
int hcnt = 0;

// �μ��� �ٲٴ� �Լ�
void swap(Data* a, Data* b);
// ���� �����͸� �ִ´�.
void putHeap(Data data);
// ������ �����͸� �����´�. (������ �� ���� �����͸� �������� �����Ѵ�.)
Data getHeap();
// �迭�� ������ ������� ������ش�.
void printArray();

int main() {
	Data input, result;

	printf("���� ������ �����͸� �Է��ϼ��� : ");
	scanf_s("%d", &input);


	while (input > 0) {
		putHeap(input);
		printf("���� ������ �����͸� �Է��ϼ��� : ");
		scanf_s("%d", &input);
	}

	// �迭�� ����غ���
	printf("\n");
	printArray();
	printf("\n");

	// ������ �� ������
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
		// i��° ���� �θ� ��带 ��ȯȯ��.
		swap(&heap[i], &heap[i / 2]);
		// �� ���� ���� �ö�ܴ�.
		i /= 2;
	}
	heap[i] = data; // ���ο� ��带 ����
	printArray();
	printf("\n");
}

Data getHeap() {
	// ù��° �� ������ 
	Data result = heap[1];

	// ���������� ù��°�� �ֱ�
	heap[1] = heap[hcnt];
	hcnt--;

	// �Ʒ��� ���ϸ鼭 �ϳ��� �������鼭 �˸��� ��ġ ã��
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