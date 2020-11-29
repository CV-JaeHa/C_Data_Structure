#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

// 큐의  초기화 
void queueInit(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

// 큐가 비었는지 확인 
int isEmpty(Queue* q) {
	if (q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}

// 큐가 꽉 찼는지 확인 
int isFull(Queue* q) {
	if (q->rear + 1 == q->front)
		return TRUE;
	else
		return FALSE;
}

// 큐에 삽입 연산
void enQueue(Queue* q, Data data) {
	if (isFull(q))
		printf("큐가 꽉 찼습니다.\n");
	else {
		q->qArr[++q->rear] = data;
	}
}

// 큐에서 삭제 연산 
Data deQueue(Queue* q) {
	if (isEmpty(q))
		printf("큐가 비었습니다.\n");
	else
		return q->qArr[++q->front];
}

// 큐의  peek연산 (첫번째 자료를 가져온다.) 
Data peek(Queue* q) {
	if (isEmpty(q))
		printf("큐가 비었습니다.\n");
	else
		return q->qArr[q->front + 1];
}

// 큐  출력하기
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