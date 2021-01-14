#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

//더미리스트를 연결해 통일성을 줌
void ListInit(List *plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));
	plist->head->next = plist->tail;
	plist->head->prev = NULL;
	plist->tail->next = NULL;
	plist->tail->prev = plist->head;
	plist->numOfData = 0;
}

//꼬리에 넣음 즉 꼬리 기준으로 짜는것을 의미
void LInsert(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;
	//plist->tail->next = newNode;
	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	plist->numOfData++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur->prev == plist->head)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *tempNode = plist->cur;
	Data tempData = tempNode->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;

	plist->numOfData--;
	free(tempNode);
	return tempData;
}

int LCount(List *plist)
{
	return plist->numOfData;
}