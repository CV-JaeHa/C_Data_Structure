#include <stdio.h>

typedef struct _node {
	int data;
	struct _node* prev;
	struct _node* next;
} Node;

Node* head = NULL, * tail = NULL, * newNode = NULL;

void InsertFront(Node* pNode, int data);
void InsertBack(Node* pNode, int data);
void DeleteFront(Node* pNode);
void DeleteBack(Node* pNode);
void printArr(Node* pNode);

int main() {
	

	return 0;
}

void InsertFront(Node* pNode, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pNode->next;
	pNode->next = newNode;
	newNode->prev = pNode;
}

void InsertBack(Node* pNode, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	pNode->next = newNode;
	newNode->prev = pNode;
	newNode->next = tail;
}

void DeleteFront(Node* pNode) {
	Node* temp;
	temp = pNode->prev;
	pNode->prev = pNode->prev->prev;
	free(temp);
}

void DeleteBack(Node* pNode) {
	Node* temp;
	temp = pNode->next;
	pNode->next = pNode->next->next;
	free(temp);
}

void printArr(Node *pNode) {
	for 
}
