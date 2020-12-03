#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

// 스태 초기화 
void stackInit(Stack* pstack) {
	pstack->top = NULL;
}

// 스택이 비었는지 확인 
int isEmpty(Stack* pstack) {
	if (pstack->top == NULL)
		return TRUE;
	else
		return FALSE;
}

// 스택의 push 연산
void push(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->top;
	pstack->top = newNode;

#ifdef DEBUG
	printf("PUSH : %c\n", data);
#endif
}

// 스택의 pop연산
Data pop(Stack* pstack) {
	Data rdata;
	Node* rnode;

	if (isEmpty(pstack)) {
		printf("stack이 비어 있습니다.");
		exit(1);
	}

	rdata = pstack->top->data;
	rnode = pstack->top;
	pstack->top = pstack->top->next;
	free(rnode);

	return rdata;
}

// 스택의 peek연산
Data peek(Stack* pstack) {
	if (isEmpty(pstack)) {
		return NULL;
	}
	return pstack->top->data;
}