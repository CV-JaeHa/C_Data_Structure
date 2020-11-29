#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"
#include <string.h>

Stack stack;
Data exp[100], result[100];

// 괄호 검사 
int isSyntaxError();

// 중위표기를 후위표기식으로 변환
void infix_to_postfix();

int main() {

	// stack 초기화 
	stackInit(&stack);

	// 수식 입력받기  
	printf("수식을 입력해주세요 : ");
	fgets(exp, 100, stdin);
	printf("\n");
	// 괄호 검사
	printf("------ 괄호검사 ---------\n");
	if (isSyntaxError()) {
		printf("괄호가 잘못됐습니다.\n");
		exit(1);
	}

	printf("------- 후위표기식 변환  --------\n");
	infix_to_postfix();


	// 후위표현식으로 출력	
	printf("후위표현식 : %s\n", result);

	return 0;
}

// 괄호 검사 --------------------//
int isSyntaxError() {
	int len = strlen(exp) - 1;

	for (int i = 0; i < len; i++) {
		switch (exp[i]) {
		case '(':
			push(&stack, exp[i]);
			break;
		case ')':
			if (isEmpty(&stack)) {
				return TRUE;
			}
			pop(&stack);
		}
	}
	if (isEmpty(&stack))
		return FALSE;
	else
		return TRUE;
}

// 중위표기를 후위표기로 변환 --------------------//
void infix_to_postfix() {
	int idx = 0; // result값에 값을 넣을 인덱스 
	Data tmp;
	int len = strlen(exp) - 1;

	// 반복문을 이용하여 후위표기식으로 변환 
	for (int i = 0; i < len; i++) {
		switch (exp[i]) {
		case '(':push(&stack, exp[i]); break;
		case ')': tmp = pop(&stack);
			while (tmp != '(') {
				result[idx++] = tmp;
				tmp = pop(&stack);
			} break;

		case '+': case '-':
			while (1) {
				tmp = peek(&stack);
				if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
					result[idx++] = pop(&stack);
				}
				else { break; };
			}
			push(&stack, exp[i]);
			break;

		case '*': case '/':
			tmp = peek(&stack);
			if (tmp == '*' || tmp == '/') 
				result[idx++] = pop(&stack);
			push(&stack, exp[i]);
			break;
		
		default:
			result[idx++] = exp[i];
			break;
		}
	}

	// 스택에 연산자가 남아 있으면
	while (!isEmpty(&stack))
		result[idx++] = pop(&stack);

	// 문자 배열 마지막에 널 값 저장
	result[idx] = NULL;
}