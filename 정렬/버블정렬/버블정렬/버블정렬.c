#include <stdio.h>
#include <stdbool.h>
#include "�⺻�Լ�.h"

void bubbleSort(int* arr, int size);

int main() {
	int size;
	int arr[] = { 68, 10, 30, 2, 16, 8, 31, 22 };

	size = sizeof(arr) / sizeof(int);
	printf("Size ũ�� : %d\n\n", size);
	printf("------ Bubble Sort -------\n");
	printArr(arr, size);
	bubbleSort(arr, size);

	return 0;
}

void bubbleSort(int* arr, int size) {
	// ��������
	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
		printArr(arr, size);
	}*/

	// ������ ��������
	bool swaping = false;
	for (int i = size - 1; i >= 0; i--) {
		swaping = false;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swaping = true;
			}
		}
		if (!swaping)
			return;
		printArr(arr, size);
	}
}