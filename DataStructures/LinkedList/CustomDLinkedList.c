#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

//데이터를 삽입
void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

//첫번째에 데이터 삽입, 처음이 아님
void FInsert(List * plist, LData data)
{
	//데이터 초기화 시켜줘야함, 자꾸 빼먹음.
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	plist->numOfData++;
}

//첫번째 참조
int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->head->next->data;
	return TRUE;
}

//다음 참조
int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next ==NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

//제거
LData LRemove(List * plist)
{
	//데이터 해제 하는거 신경 안써줌
	LData tempData = plist->cur->data;
	//주소를 가지는 노드를 만들어 차후에 지워주기 위해 가르킴.
	Node* tempNode = plist->cur;
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(tempNode);
	plist->numOfData--;


	return tempData;
}

//갯수 출력
int LCount(List * plist)
{
	return plist->numOfData;
}

//방법을 정해줌
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

//정렬 기준에 맞춰 데이터 삽입
void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* dummyNode = plist->head;

	newNode->data = data;

	while (dummyNode->next != NULL) {
		if (plist->comp(data, dummyNode->next->data) == 0)
			break;
		
		dummyNode = dummyNode->next;
	}

	newNode->next = dummyNode->next;
	dummyNode->next = newNode;
	plist->numOfData++;
}
