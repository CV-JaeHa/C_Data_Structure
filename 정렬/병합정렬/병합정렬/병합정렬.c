#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "기본함수.h"

int size;
int sort[8];  // 정렬된 결과가 들어갈 배열

void merge(int* arr, int m, int mid, int n);
void mergeSort(int* arr, int m, int n);

int main() {
	int arr[] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = sizeof(arr) / sizeof(int);

	printf("\n------ Merge Sort -------\n");
	printf("\n정렬 전 : ");
	printArr(arr, size);
	mergeSort(arr, 0, size - 1);
	printf("\n\n정렬 후 : ");
	printArr(arr, size);
	printf("\n");

	return 0;
}

void merge(int* arr, int m, int mid, int n) {
	int i = m, j = mid + 1, k = m;

	while (i <= mid && j <= n) {
		if (arr[i] < arr[j])
			sort[k++] = arr[i++];
		else
			sort[k++] = arr[j++];
	}

	// 남은 데이터 모두 삽입하기
	for (; i <= mid; i++)
		sort[k++] = arr[i];

	for (; j <= n; j++)
		sort[k++] = arr[j];

	// arr에 값 넣어주기
	for (i = m; i <= n; i++)
		arr[i] = sort[i];
}

void mergeSort(int* arr, int m, int n) {
	if (m >= n) return;

	int mid = (m + n) / 2;
	mergeSort(arr, m, mid);
	mergeSort(arr, mid + 1, n);

	merge(arr, m, mid, n);
}

