#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;
typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int top;
} ArrayStack;

typedef ArrayStack Stack;

// ���� �ʱ�ȭ 
void stackInit(Stack* pstack);

// ������ ������� Ȯ�� 
int isEmpty(Stack* pstack);

// ������ push ����
void push(Stack* pstack, Data data);

// ������ pop����
Data pop(Stack* pstack);

// ������ peek����
Data peek(Stack* pstack);
