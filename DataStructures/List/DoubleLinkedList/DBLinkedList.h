#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

//다른 노드와 같지만 이전노드의 주소를 가진 것에서 차이가 있다.
typedef struct _node
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

//before노드가 없음.
typedef struct _dbLinkedList
{
	Node * head;
	Node * tail;
	Node * cur;
	int numOfData;

} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);

Data LRemove(List *plist);
int LCount(List * plist);

#endif