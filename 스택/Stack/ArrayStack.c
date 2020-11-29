#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���� �ʱ�ȭ 
void stackInit(Stack* pstack) {
	pstack->top = -1;
}

// ������ ������� Ȯ�� 
int isEmpty(Stack* pstack) {
	if (pstack->top == -1)
		return TRUE;
	else
		return FALSE;
}

// ������ push ����
void push(Stack* pstack, Data data) {
	pstack->top += 1;
	pstack->stackArr[pstack->top] = data;
}

// ������ pop����
Data pop(Stack* pstack) {
	Data rdata;

	if (isEmpty(pstack)) {
		printf("stack�� ��� �ֽ��ϴ�.");
		exit(1);
	}
	rdata = pstack->stackArr[pstack->top];
	pstack->top--;

	return rdata;
}

// ������ peek����
Data peek(Stack* pstack) {
	if (isEmpty(pstack)) {
		printf("stack�� ��� �ֽ��ϴ�.");
		exit(1);
	}
	return pstack->stackArr[pstack->top];
}
