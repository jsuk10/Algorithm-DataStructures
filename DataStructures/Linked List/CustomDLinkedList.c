#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

//초기화 해주는 함수
void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

//tail에 삽입
void LInsert(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	plist->numOfData++;
}

//head에 삽입
void LInsertFront(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	plist->numOfData++;
}

//처음 참조할 경우
//flase가 출력될경우는 데이터(노드)가 없는 경우
//true는 있고 현재 인덱스에 cur과 before를 넣어줌
int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->cur = plist->tail->next;
	plist->before = plist->tail;

	*pdata = plist->cur->data;
	return TRUE;
}

//다음 인덱스를 참조할 경우
int LNext(List *plist, Data *pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

//데이터를 지워줌
//지울 데이터가 꼬리를 가르킬 경우 주의해서 짜볼것.
Data LRemove(List *plist)
{

	Data DataTemp = plist->cur->data;
	Node *NodeTemp = plist->cur;

	if (NodeTemp == plist->tail)
	{
		if (plist->tail == plist->tail->next)
		{
			plist->tail = NULL;
		}
		else
		{
			plist->tail == plist->before;
		}
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(NodeTemp);
	plist->numOfData--;
	return DataTemp;
}

int LCount(List *plist)
{
	return plist->numOfData;
}
