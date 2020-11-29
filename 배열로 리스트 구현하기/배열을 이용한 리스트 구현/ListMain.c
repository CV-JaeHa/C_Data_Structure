#include <stdio.h>
#include "ArrayList.h"

int main() {
	int data = 0;
	int total = 0;
	//리스트 생성 및 초기화
	List plist;
	ListInit(&plist);
	
	//정수 1부터 9까지 리스트에 저장
	for (int i = 1; i < 10; i++) {
		LInsert(&plist, i);
	}
	
	//리스트에 저장된 값을 순차적으로 읽어 그 합을 출력
	if (LFirst(&plist, &data)) {
		total += data;
		while (LNext(&plist, &data))
			total += data;
	}
	printf("리스트의 합 : %d\n", total);

	//리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값 삭제
	if (LFirst(&plist, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&plist);
		while (LNext(&plist, &data))
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&plist);
	}

	//리스트의 저장된 값 출력
	printf("리스트에 저장된 값 : ");
	if (LFirst(&plist, &data)) {
		printf("%d ", data);
		while (LNext(&plist, &data))
			printf("%d ", data);
	}
	printf("\n");

	return 0;
}