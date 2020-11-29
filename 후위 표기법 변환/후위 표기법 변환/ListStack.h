#pragma once
#define TRUE 1
#define FALSE 0
#define STACK_LEN 100
#define DEBUG

typedef char Data;
typedef struct _node {
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack {
	Node* top;
} ListStack;

typedef ListStack Stack;

// 스택 초기화 
void stackInit(Stack* pstack);

// 스택이 비었는지 확인 
int isEmpty(Stack* pstack);

// 스택의 push 연산
void push(Stack* pstack, Data data);

// 스택의 pop연산
Data pop(Stack* pstack);

// 스택의 peek연산
Data peek(Stack* pstack);