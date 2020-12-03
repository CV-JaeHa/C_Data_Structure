#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List* plist, LData pdata) {
	if (plist->numOfData >= LIST_LEN) {
		printf("¸¸µÎ±èÄ¡\n");
		return;
	}
	for (int i = plist->numOfData - 1; i >= plist->curPosition; i--) {
		plist->arr[i + 1] = plist->arr[i];
	}
	plist->curPosition++;
	plist->arr[plist->curPosition] = pdata;
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData <= 0)
		return FALSE;
	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= plist->numOfData-1)
		return FALSE;
	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) {
	if (plist->numOfData <= 0 && plist->curPosition < 0)
		return FALSE;
	LData num = plist->arr[plist->curPosition];
	for (int i = plist->curPosition + 1; i < plist->numOfData - 1; i++) {
		plist->arr[i - 1] = plist->arr[i];
	}
	plist->numOfData--;
	plist->curPosition--;
	return num;
}

int LCount(List* plist) {
	for (int i = 0; i < plist->numOfData; i++)
		return i;
}