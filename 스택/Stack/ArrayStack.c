#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// 스택 초기화 
void stackInit(Stack* pstack) {
	pstack->top = -1;
}

// 스택이 비었는지 확인 
int isEmpty(Stack* pstack) {
	if (pstack->top == -1)
		return TRUE;
	else
		return FALSE;
}

// 스택의 push 연산
void push(Stack* pstack, Data data) {
	pstack->top += 1;
	pstack->stackArr[pstack->top] = data;
}

// 스택의 pop연산
Data pop(Stack* pstack) {
	Data rdata;

	if (isEmpty(pstack)) {
		printf("stack이 비어 있습니다.");
		exit(1);
	}
	rdata = pstack->stackArr[pstack->top];
	pstack->top--;

	return rdata;
}

// 스택의 peek연산
Data peek(Stack* pstack) {
	if (isEmpty(pstack)) {
		printf("stack이 비어 있습니다.");
		exit(1);
	}
	return pstack->stackArr[pstack->top];
}
