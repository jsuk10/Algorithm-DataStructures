#ifndef __USEFULL_HEAP_H__
#define __USEFULL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

// typedef char HData;
typedef int HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heapElem
{
	PriorityComp *comp; // 값이 작을수록 높은 우선순위
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

int GetPartenIndex(int index);
int GetRightChildIndex(int index);
int GetLeftChildIndex(int index);
int GetHipPriChildIndex(Heap *ph, int index);

#endif