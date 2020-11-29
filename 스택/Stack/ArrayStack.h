#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;
typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int top;
} ArrayStack;

typedef ArrayStack Stack;

// 스택 초기화 
void stackInit(Stack* pstack);

// 스택이 비었는지 확인 
int isEmpty(Stack* pstack);

// 스택의 push 연산
void push(Stack* pstack, Data data);

// 스택의 pop연산
Data pop(Stack* pstack);

// 스택의 peek연산
Data peek(Stack* pstack);
