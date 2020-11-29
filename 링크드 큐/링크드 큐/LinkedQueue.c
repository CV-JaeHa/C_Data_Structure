#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 큐의 초기화 
void queueInit(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

// 큐가 비었는지 확인 
int isEmpty(Queue* q) {
	if (q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}

// 큐에 삽입 연산
void enQueue(Queue* q, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	printf("Insert - %d ", data);

	if (isEmpty(q)) {
		q->front = newNode;
	}
	else {
		q->rear->next = newNode;
	}
	q->rear = newNode;
}

// 큐에서 삭제 연산 
Data deQueue(Queue* q) {
	Node* tmp;
	Data rdata;
	if (isEmpty(q)) {
		printf("큐가 비어있습니다.");
		return -1;
	}
	printf("delete - %d ", q->front->data);

	rdata = q->front->data;
	tmp = q->front;

	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	
	free(tmp);
	return rdata;
}

// 큐의 peek연산 (첫번째 자료를 가져온다.) 
Data peek(Queue* q) {
	return q->front->data;
}

// 큐 출력하기
void printQueue(Queue* q) {
	int i;
	Node *pNode;

	printf(" |");
	pNode = q->front;
	while (pNode != NULL) {
		printf(" %d |", pNode->data);
		pNode = pNode->next;
	}
	printf("\n");
}