#include <stdio.h>
#include <stdbool.h>
#include "�⺻�Լ�.h"

// ��������
void insertSort(int* arr, int size);

int main() {
	int size;
	int arr[] = { 68, 10, 30, 2, 16, 8, 31, 22 };

	size = sizeof(arr) / sizeof(int);
	printf("Size ũ�� : %d\n\n", size);
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
            if (arr[j] > key) {       //key�� ���ڸ��� �ϳ��� ���鼭 ��
                arr[j + 1] = arr[j];  //���ڸ� ���� key������ ũ�ٸ� �ϳ��� �̵�
            }
            else {                  //key���� ���� ���� ������ break;
                break;
            }
        }
        arr[j + 1] = key;             //�� �ڸ��� key���� �ִ´�.
        printArr(arr, size);
    }
}