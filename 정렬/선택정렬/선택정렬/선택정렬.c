#include <stdio.h>
#include <stdlib.h>

// num 값 바꾸기
void swap(int* num1, int* num2);
// Arr 값 모두 출력하기
void printArr(int* arr, int size);
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

void swap(int* num1, int* num2) {
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void printArr(int* arr, int size) {
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
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