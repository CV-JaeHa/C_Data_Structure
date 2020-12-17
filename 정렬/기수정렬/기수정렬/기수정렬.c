#include <stdio.h>
#include <windows.h>
#include "큐.h"
#include "기본함수.h"

int size;
// 기수 정렬
void radixSort(int* arr, int size);

int main() {
	int arr[] = { 192, 168, 30, 2, 825, 16, 335, 20, 80, 5, 922 };
	size = sizeof(arr) / sizeof(int);

	printf("\n------- Radix Sort -------\n\n");
	printf("정렬 전 : ");
	printArr(arr, size);
	radixSort(arr, 0, size - 1);
	printf("정렬 후 : ");
	printArr(arr, size);
	printf("\n");

	return 0;
}

void radixSort(int* arr, int size) {
	int k, i, max = arr[0];
	int j = 0;
	Queue queue[10];

	for (i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	for (k = 1; k <= max; k *= 10) {
		for (i = 0; i < 10; i++) queueInit(&queue[i]);

		for (i = 0; i < size; i++) {
			enqueuer(&queue[arr[i] / k % 10], arr[i]);
		}
		j = 0;
		for (i = 0; i < 10; i++) {
			while (!isEmpty(&queue[i])) {
				arr[j++] = dequeuer(&queue[i]);
			}
		}
		printArr(arr, size);

	}
}