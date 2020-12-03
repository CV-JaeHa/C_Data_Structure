#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ť�� �ʱ�ȭ 
void queueInit(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

// ť�� ������� Ȯ�� 
int isEmpty(Queue* q) {
	if (q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}

// ť�� ���� ����
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

// ť���� ���� ���� 
Data deQueue(Queue* q) {
	Node* tmp;
	Data rdata;
	if (isEmpty(q)) {
		printf("ť�� ����ֽ��ϴ�.");
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

// ť�� peek���� (ù��° �ڷḦ �����´�.) 
Data peek(Queue* q) {
	return q->front->data;
}

// ť ����ϱ�
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