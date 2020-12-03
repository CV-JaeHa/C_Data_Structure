#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

int isMatch(Data source, Data dest) {
	if ((source == '(' && dest == ')')
		|| (source == '[' && dest == ']')
		|| (source == '{' && dest == '}')) {
		return TRUE;
	}
	return FALSE;
}

int main() {
	Stack stack;
	Data exp[100], * ch;
	stackInit(&stack);
	fgets(exp, 100, stdin);
	ch = exp;
	while (*ch != '\0') {
		switch (*ch) {
		case '[': case '{': case '(':
			push(&stack, *ch); break;

		case ')': case '}': case ']':
			if (isMatch(peek(&stack), *ch))
				pop(&stack);
			else {
				printf("error.404");
				exit(1);
			}
		} 
		ch++;
	}
	if (isEmpty(&stack))
		printf("��ȣ�� ���������� ��� �Ǿ����ϴ�.");
	else
		printf("��ȣ�� �߸� �Ǿ����ϴ�.\n");
}