#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if (pdeq->head == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pdeq->head;

    //if(DQIsEmpty(pdeq) == TREU)
    if (pdeq->head == NULL)
    {
        //맨 처음에는 둘다 NULL이므로 꼬리에 연결 해줌
        pdeq->tail = newNode;
    }
    else
    {
        //먼저 입력된 머리의 앞을 새로운 노드로 설정함
        pdeq->head->prev = newNode;
    }
    //맨 처음에 들어가기 때문에 앞에 가르키는게 없어야함
    newNode->prev = NULL;
    //헤드에 리스트를 연결해주는것으로 앞에 삽입 완료
    pdeq->head = newNode;
}
void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;

    //if(DQIsEmpty(pdeq) == TREU)
    if (pdeq->tail == NULL)
    {
        pdeq->head = newNode;
    }
    else
    {
        pdeq->tail->next = newNode;
    }
    //맨 처음에 들어가기 때문에 앞에 가르키는게 없어야함
    newNode->next = NULL;
    //헤드에 리스트를 연결해주는것으로 앞에 삽입 완료
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
    Node *tempNode = pdeq->head;
    Data tempData = tempNode->data;

    if (DQIsEmpty(pdeq) == TRUE)
    {
        printf("Deque is Empty!!");
        exit(-1);
    }
    pdeq->head = pdeq->head->next;
    free(tempNode);
    if (pdeq->head == NULL)
    {
        pdeq->tail = NULL;
    }
    else
    {
        pdeq->head->prev = NULL;
    }

    return tempData;
}
Data DQRemoveLast(Deque *pdeq)
{
    Node *tempNode = pdeq->tail;
    Data tempData = tempNode->data;

    if (DQIsEmpty(pdeq) == TRUE)
    {
        printf("Deque is Empty!!");
        exit(-1);
    }

    pdeq->tail = pdeq->tail->prev;
    free(tempNode);

    if (pdeq->tail == NULL)
    {
        pdeq->head = NULL;
    }
    else
    {
        pdeq->tail->next = NULL;
    }

    return tempData;
}

Data DQGetFirst(Deque *pdeq)
{
    if (DQIsEmpty(pdeq) == TRUE)
    {
        printf("Deque is Empty!!");
        exit(-1);
    }

    return pdeq->head->data;
}

Data DQGetLast(Deque *pdeq)
{

    if (DQIsEmpty(pdeq) == TRUE)
    {
        printf("Deque is Empty!!");
        exit(-1);
    }

    return pdeq->tail->data;
}