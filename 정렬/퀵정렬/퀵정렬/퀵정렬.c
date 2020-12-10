#include <stdio.h>
#include "헤더.h"

// 피봇구하기 (기준값 구하기)
int getPivot(int* arr, int start, int end);

// 퀵정렬
void quickSort(int* arr, int start, int end);

int main() {
	int size;
	int arr[] = { 68, 10, 30, 2, 16, 8, 31, 22 };

	size = sizeof(arr) / sizeof(int);

	printf("------ Quick Sort -------");
	printArr(arr, size);
	quickSort(arr, 0, size-1);

	printArr(arr, size);

	return 0;
}

int getPivot(int* arr, int start, int end) {
	int pivot = end;
	int i = start - 1;

	for (int j = start; j < end; j++) {
		if (arr[pivot] > arr[j])
			swap(&arr[++i], &arr[j]);
	}

	swap(&arr[++i], &arr[pivot]);

	return i;
}

void quickSort(int* arr, int start, int end) {
	if (start > end) return;
	int pivot = getPivot(arr, start, end);
	
	// 피봇 기준으로 왼쪽 정렬
	quickSort(arr, start, pivot - 1);
	// 피봇 기준으로 오른쪽 정렬
	quickSort(arr, pivot + 1, end);
}