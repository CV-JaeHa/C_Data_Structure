#include <stdio.h>
#include "ArrayList.h"

int main() {
	int data = 0;
	int total = 0;
	//����Ʈ ���� �� �ʱ�ȭ
	List plist;
	ListInit(&plist);
	
	//���� 1���� 9���� ����Ʈ�� ����
	for (int i = 1; i < 10; i++) {
		LInsert(&plist, i);
	}
	
	//����Ʈ�� ����� ���� ���������� �о� �� ���� ���
	if (LFirst(&plist, &data)) {
		total += data;
		while (LNext(&plist, &data))
			total += data;
	}
	printf("����Ʈ�� �� : %d\n", total);

	//����Ʈ�� ����� ���� �� 2�� ����� 3�� ����� �ش��ϴ� �� ����
	if (LFirst(&plist, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&plist);
		while (LNext(&plist, &data))
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&plist);
	}

	//����Ʈ�� ����� �� ���
	printf("����Ʈ�� ����� �� : ");
	if (LFirst(&plist, &data)) {
		printf("%d ", data);
		while (LNext(&plist, &data))
			printf("%d ", data);
	}
	printf("\n");

	return 0;
}