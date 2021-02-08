#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack)
{
	pstack->head = NULL;
}
int SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;

	/*
	데이터를 쌓기 때문에 Null체크를 통해서 따로 할 필요 없이 다음 노드를 헤드로 가르키고
	헤드를 새로 업데이트 해주면 된다.
	if (pstack->head != NULL)
	{
		pstack->head->next = newNode;
	}
*/
	pstack->head = newNode;
}
Data SPop(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}

	Data tempData = pstack->head->data;
	Node *tempNode = pstack->head;

	pstack->head = pstack->head->next;

	free(tempNode);
	return tempData;
}
Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}

	return pstack->head->data;
}