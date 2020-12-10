#pragma once
#include <stdio.h>

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

// ���� ����
void insertSort(int* arr, int start, int end, int h) {
	int i, j, tmp;

	for (i = start; (i + h) <= end; i += h) {
		tmp = arr[i + h];
		for (j = i; j >= 0; j -= h) {
			if (tmp > arr[j]) break;
			arr[j + h] = arr[j];
		}
		arr[j + h] = tmp;
	}
}