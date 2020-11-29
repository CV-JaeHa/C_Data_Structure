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

	//���� ��Ʈ �����
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	//��� ����
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

	//���Ḯ��Ʈ ����ϱ�
	printf("���Ḯ��Ʈ ����ϱ� : ");
	for (pNode = head->next; pNode != NULL; pNode = pNode->next) {
		printf("%d ", pNode->data);
	}
	printf("\n\n");

	//���Ḯ��Ʈ �� �����Ͱ� 2�� ����� ��� ����
	for (pNode = head; pNode != NULL; pNode = pNode->next) {
		if (pNode->next->data % 2 == 0)
			LDelete(pNode);
	}

	//���Ḯ��Ʈ ����ϱ�
	printf("���� ���Ḯ��Ʈ ����ϱ� : ");
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