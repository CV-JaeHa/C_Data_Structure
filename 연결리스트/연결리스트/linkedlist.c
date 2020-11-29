#include <stdio.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

Node* head = NULL, * tail = NULL, * newNode = NULL;

int LInsert(Node* pNode, int data);
int LDelete(Node* pNode);

int main()
{
	Node* head, * pNode;
	int data;
	int i;

	//더미 노트 만들기
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	//노드 삽입
	scanf("%d", &data);
	while (data > 0) {
		for (pNode = head; pNode != NULL; pNode = pNode->next) {
			if ((pNode->next == NULL) || (pNode->next->data >= data)) {
				LInsert(pNode, data);
				break;
			}
		}
		scanf("%d", &data);
	}

	//연결리스트 출력하기
	printf("연결리스트 출력하기 : ");
	for (pNode = head->next; pNode != NULL; pNode = pNode->next) {
		printf("%d ", pNode->data);
	}
	printf("\n\n");

	//연결리스트 중 데이터가 2인 배수인 노드 삭제
	for (pNode = head; pNode != NULL; pNode = pNode->next) {
		if (pNode->next->data % 2 == 0)
			LDelete(pNode);
	}

	//연결리스트 출력하기
	printf("최종 연결리스트 출력하기 : ");
	for (pNode = head->next; pNode != NULL; pNode = pNode->next) {
		printf("%d ", pNode->data);
	}
	printf("\n");
}

int LInsert(Node* pNode, int data) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode-> data = data;
	newNode->next = pNode->next;
	pNode->next = newNode;
}

int LDelete(Node* pNode) {
	Node* temp;
	temp = pNode->next;
	pNode->next = pNode->next->next;
	free(temp);
}