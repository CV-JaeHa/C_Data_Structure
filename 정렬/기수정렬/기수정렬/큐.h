#pragma once
#include <stdio.h>
#define MAX_SIZE 20

typedef struct _QUEUE {
	int arr[MAX_SIZE];
	int front, rear;
}Queue;

int isEmpty(Queue* q) {
	if (q->front == q->rear)
		return 1;
	return 0;
}

void queueInit(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

void enqueuer(Queue* q, int data) {
	if ((q->rear + 1) % MAX_SIZE == q->front) {
		printf("큐가 꽉 찼습니다.");
		return ;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->arr[q->rear] = data;
}

int dequeuer(Queue* q) {
	if (q->front == q->rear) {
		printf("큐가 비었습니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_SIZE;

	return q->arr[q->front];
}
