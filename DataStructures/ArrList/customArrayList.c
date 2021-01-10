#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
    plist->numOfData = 0;
    plist->curPosition = -1;
}

void LInsert(List* plist, LData data) {
    //예외처리 빼먹음
    if (plist->numOfData > LIST_LEN) {
        printf("저장 불가");
        return;
    }
    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List* plist, LData* pdata) {
    if (plist->numOfData == 0) {
        return FALSE;
    }
    
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}
int LNext(List* plist, LData* pdata) {
    if (plist->curPosition >= plist->numOfData - 1)
        return FALSE;
    //*pdata로 써야하는 부분인데 pdata로 씀
    //포인터 참조 포인터 다시 공부할것.
    *pdata = plist->arr[++(plist->curPosition)];
    return TRUE;
};

LData LRemove(List* plist) {
    LData temp = plist->arr[plist->curPosition];
    for (int i = plist->curPosition; i < (plist->numOfData)-1; i++) {
        plist->arr[i] = plist->arr[i + 1];
    }
    plist->numOfData--;
    //빼먹은 부분 만약 되돌리지 않으면 한칸 앞으로 더 나가게됨 이게 없을 경우 3번을 삭제하고 4번을 참조하므로 실제로는 삭제후 한칸 더가서 참조하는것이됨
    plist->curPosition--; 
    return temp;
};
int LCount(List* plist) {
    return plist->numOfData; 
}