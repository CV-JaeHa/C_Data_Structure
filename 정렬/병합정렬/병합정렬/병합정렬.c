#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "�⺻�Լ�.h"

int size;
int sort[8];  // ���ĵ� ����� �� �迭

void merge(int* arr, int m, int mid, int n);
void mergeSort(int* arr, int m, int n);

int main() {
	int arr[] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = sizeof(arr) / sizeof(int);

	printf("\n------ Merge Sort -------\n");
	printf("\n���� �� : ");
	printArr(arr, size);
	mergeSort(arr, 0, size - 1);
	printf("\n\n���� �� : ");
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

	// ���� ������ ��� �����ϱ�
	for (; i <= mid; i++)
		sort[k++] = arr[i];

	for (; j <= n; j++)
		sort[k++] = arr[j];

	// arr�� �� �־��ֱ�
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

