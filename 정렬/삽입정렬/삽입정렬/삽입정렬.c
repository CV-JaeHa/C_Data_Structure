#include <stdio.h>
#include <stdbool.h>
#include "기본함수.h"

// 삽입정렬
void insertSort(int* arr, int size);

int main() {
	int size;
	int arr[] = { 68, 10, 30, 2, 16, 8, 31, 22 };

	size = sizeof(arr) / sizeof(int);
	printf("Size 크기 : %d\n\n", size);
	printf("------ Insert Sort -------\n");
	printArr(arr, size);
	insertSort(arr, size);

	return 0;
}

void insertSort(int* arr, int size) {
    int i, j;
    int key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > key) {       //key의 앞자리를 하나씩 보면서 비교
                arr[j + 1] = arr[j];  //앞자리 값이 key값보다 크다면 하나씩 이동
            }
            else {                  //key보다 작은 값이 나오면 break;
                break;
            }
        }
        arr[j + 1] = key;             //그 자리에 key값을 넣는다.
        printArr(arr, size);
    }
}