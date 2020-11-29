#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// 노드추가 flag : 'F'-앞에 추가,  'L'-뒤에 추가  
void LInsert(List* plist, Data data, char flag)
{
	// newNode로 노드를 추가한 후 링크를 연결해 주고 numOfData 증가 
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		if (flag == 'L') {
			plist->tail = newNode;
		}
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

// 노드를 삭제한다. (리턴값으로 삭제된 데이터를 넘겨준다.) 
Data LRemove(List* plist)
{
	Node* tmp;
	tmp = plist->cur;
	Data rdata = plist->cur->data;
	
	if (tmp == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail == NULL;
		else
			plist->tail = plist->before;
	}
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(tmp);
	(plist->numOfData)--;

	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}