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

// ����ǥ��� �������� ��� 
int calc_postfix();

int main() {

	// stack �ʱ�ȭ 
	stackInit(&stack);

	printf("------- ���� ��� --------\n");
	int calc_val = calc_postfix();
	printf("������ ����� : %d \n", calc_val);

	return 0;
}

// ����ǥ��� ����ϱ� 
int calc_postfix() {
	int x, y, z, i;
	int len = strlen(exp);

	// ���� ��� �˰���  - ���ڸ� ���ڷ� ��ȯ(1����) -->  toData
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
	
	// ����� ���� 
	return pop(&stack);
}