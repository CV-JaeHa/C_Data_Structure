#include <stdio.h>
#include <stdlib.h>

typedef char Data;
typedef struct _node {
	Data data;
	struct _node* leftchild;
	struct _node* rightchild;
} Node;
typedef Node tree;

Node A1 = { 'H', NULL, NULL };
Node A2 = { 'I', NULL, NULL };
Node A3 = { 'D', &A1, &A2 };
Node A4 = { 'E', NULL, NULL };
Node A5 = { 'B', &A3, &A4 };
Node A6 = { 'F', NULL, NULL };
Node A7 = { 'G', NULL, NULL };
Node A8 = { 'C', &A6, &A7 };
Node A9 = { 'A', &A5, &A8 };
Node* root1 = &A9;

Node B1 = { 'A', NULL, NULL };
Node B2 = { 'B', NULL, NULL };
Node B3 = { '/', &B1, &B2 };
Node B4 = { 'C', NULL, NULL };
Node B5 = { '*', &B3, &B4 };
Node B6 = { 'D', NULL, NULL };
Node B7 = { '/', &B5, &B6 };
Node B8 = { 'E', NULL, NULL };
Node B9 = { '+', &B7, &B8 };
Node* root2 = &B9;

void preorder(tree* ptr) {
	if (ptr != NULL) {
		printf("%c", ptr->data);
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}

void inorder(tree* ptr) {
	if (ptr != NULL) {
		inorder(ptr->leftchild);
		printf("%c", ptr->data);
		inorder(ptr->rightchild);
	}
}

void postorder(tree* ptr) {
	if (ptr != NULL) {
		postorder(ptr->leftchild);
		postorder(ptr->rightchild);
		printf("%c", ptr->data);
	}
}

int main() {
	//root1
	printf("preorder : ");
	preorder(root1);
	printf("\n");

	printf("inorder : ");
	inorder(root1);
	printf("\n");

	printf("postorder : ");
	postorder(root1);
	printf("\n");


	//root2
	printf("preorder : ");
	preorder(root2);
	printf("\n");

	printf("inorder : ");
	inorder(root2);
	printf("\n");

	printf("postorder : ");
	postorder(root2);
	printf("\n");

	return 0;
}