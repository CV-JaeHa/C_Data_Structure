#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListStack.h"

Stack stack;
char exp[100] = "53+42+*";;

Data toData(char ch) {
	switch (ch) {
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}
	return 0;
}

// 후위표기식 스택으로 계산 
int calc_postfix();

int main() {

	// stack 초기화 
	stackInit(&stack);

	printf("------- 수식 계산 --------\n");
	int calc_val = calc_postfix();
	printf("수식의 결과값 : %d \n", calc_val);

	return 0;
}

// 후위표기식 계산하기 
int calc_postfix() {
	int x, y, z, i;
	int len = strlen(exp);

	// 수식 계산 알고리즘  - 문자를 숫자로 변환(1문자) -->  toData
	for (i = 0; i < len; i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			y = pop(&stack);
			x = pop(&stack);
			switch (exp[i]) {
			case '+': z = x + y; break;
			case '-': z = x - y; break;
			case '*': z = x * y; break;
			case '/': z = x / y; break;
			}
			push(&stack, z);
		}
		else
			push(&stack, toData(exp[i]));
	}
	
	// 결과값 리턴 
	return pop(&stack);
}