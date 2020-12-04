#include <stdio.h>
#include "헤더.h"

// 선택정렬
void selectionSort(int* arr, int size);

int main() {
	int size;
	int arr[] = { 68, 10, 30, 2, 16, 8, 31, 22 };

	size = sizeof(arr) / sizeof(int);

	printf("------ Selection Sort -------");
	printArr(arr, size);
	selectionSort(arr, size);

	return 0;
}

void selectionSort(int* arr, int size) {
	int min;

	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
		printArr(arr, size);
	}
}