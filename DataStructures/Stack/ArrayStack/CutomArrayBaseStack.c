#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    pstack->stackArr[++(pstack->topIndex)] = data;
}

Data SPop(Stack *pstack)
{
    if(SIsEmpty(pstack)){
        printf("스택이 비어있음.");
        //프로그램을 바로 종료하는 함수
        exit(-1);
    }

    return pstack->stackArr[(pstack->topIndex)--];
}

Data SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack)){
        printf("스택이 비어있음.");
        //프로그램을 바로 종료하는 함수
        exit(-1);
    }
    return pstack->stackArr[(pstack->topIndex)];
}