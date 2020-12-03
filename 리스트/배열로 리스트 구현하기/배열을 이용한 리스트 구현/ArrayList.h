#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
typedef int LData;

typedef struct __ArraryList {
	LData arr[LIST_LEN];
	LData numOfData;
	LData curPosition;
}List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);