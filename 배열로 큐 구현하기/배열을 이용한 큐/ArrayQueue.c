#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

// ť��  �ʱ�ȭ 
void queueInit(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

// ť�� ������� Ȯ�� 
int isEmpty(Queue* q) {
	if (q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}

// ť�� �� á���� Ȯ�� 
int isFull(Queue* q) {
	if (q->rear + 1 == q->front)
		return TRUE;
	else
		return FALSE;
}

// ť�� ���� ����
void enQueue(Queue* q, Data data) {
	if (isFull(q))
		printf("ť�� �� á���ϴ�.\n");
	else {
		q->qArr[++q->rear] = data;
	}
}

// ť���� ���� ���� 
Data deQueue(Queue* q) {
	if (isEmpty(q))
		printf("ť�� ������ϴ�.\n");
	else
		return q->qArr[++q->front];
}

// ť��  peek���� (ù��° �ڷḦ �����´�.) 
Data peek(Queue* q) {
	if (isEmpty(q))
		printf("ť�� ������ϴ�.\n");
	else
		return q->qArr[q->front + 1];
}

// ť  ����ϱ�
void printQueue(Queue* q) {
	int i;

	for (i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (!(q->qArr[i] > 0 && q->qArr[i] < 100))
			printf("   |");
		else
			printf(" %d |", q->qArr[i]);
	}

	printf("\n");
}