#include <stdio.h>
#include "기본함수.h"

void shellSort(int* arr, int size);

int main() {
	int size;
	int arr[] = { 68, 10, 30, 2, 16, 8, 31, 22 };

	size = sizeof(arr) / sizeof(int);

	printf("\n------ Shell Sort -------\n");
	printf("\n정렬 전 : ");
	printArr(arr, size);
	shellSort(arr, size);
	printf("\n\n정렬 후 : ");
	printArr(arr, size);
	printf("\n");

	return 0;
}

void shellSort(int* arr, int size) {
	for (int h = size / 2; h > 0; h /= 2) {
		for (int i = 0; (i + h) < size; i++)
			insertSort(arr, i, size - 1, h);
	}
}