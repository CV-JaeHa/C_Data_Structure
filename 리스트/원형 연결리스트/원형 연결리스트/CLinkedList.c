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

// ����߰� flag : 'F'-�տ� �߰�,  'L'-�ڿ� �߰�  
void LInsert(List* plist, Data data, char flag)
{
	// newNode�� ��带 �߰��� �� ��ũ�� ������ �ְ� numOfData ���� 
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

// ��带 �����Ѵ�. (���ϰ����� ������ �����͸� �Ѱ��ش�.) 
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