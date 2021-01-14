#include <stdio.h>
#include "../../List/Cricular Linekd List/CLinkedList.h"
#include "../../List/Cricular Linekd List/CustomeCLinkedList.c"
#include "CLLBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->plist = (List *)malloc(sizeof(List));
    ListInit(pstack->plist);
}

int SIsEmpty(Stack *pstack)
{
    //모범
    //if(LCount(pstack->plist) == 0)
    if (pstack->plist->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    LInsertFront(pstack->plist, data);
}
Data SPop(Stack *pstack)
{
    //return LRemove(pstack->plist);
    Data tempData;
    LFirst(pstack->plist, &tempData);
    LRemove(pstack->plist);
    return tempData;
}
Data SPeek(Stack *pstack)
{
    Data tempData;
    LFirst(pstack->plist, &tempData);
    return tempData;
}