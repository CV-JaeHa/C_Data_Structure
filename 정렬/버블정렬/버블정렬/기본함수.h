#pragma once

// ���� �ٲ��ֱ�
void swap(int* num1, int* num2) {
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

// �迭 ������ֱ�
void printArr(int* arr, int size) {
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}