#pragma once
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 5

typedef int Data;

typedef struct _node {
	int data;
	struct _node* next;
} Node;

typedef struct _ListQueue {
	Node* front;
	Node* rear;
} Queue;


// 큐의  초기화 
void queueInit(Queue* q);

// 스택이 비었는지 확인 
int isEmpty(Queue* q);

// 큐에 삽입 연산
void enQueue(Queue* q, Data data);

// 큐에서 삭제 연산 
Data deQueue(Queue* q);

// 큐 peek연산
Data peek(Queue* q);

// 큐 출력하기
void printQueue(Queue* q);