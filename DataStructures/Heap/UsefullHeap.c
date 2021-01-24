#include "UsefullHeap.h"

//초기화
void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    //첫번째가 높으면 0보다 높게 두번째가 높으면 0보다 작게 같으면 0 반환
    ph->comp = pc;
}

//비어있는지 판단
int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetPartenIndex(int index)
{
    return index / 2;
}
int GetRightChildIndex(int index)
{
    return index * 2 + 1;
}
int GetLeftChildIndex(int index)
{
    return index * 2;
}

//양쪽중에 우선순위가 높은 값을 얻어옴.
int GetHipPriChildIndex(Heap *ph, int index)
{
    //numOfData는 마지막 원소의 index를 나타내는 것과 동일하다
    //자식 노드가 없다면
    //GetLeftChildIndex에 값이 numOfData보다 큰 경우는 노드가 존재하지 않음.
    if (GetLeftChildIndex(index) > ph->numOfData)
        return 0;
    //자식노드가 왼쪽 하나만 존재할 경우
    //마지막 노드가 좌측에 있는 경우
    else if (GetLeftChildIndex(index) == ph->numOfData)
    {
        return GetLeftChildIndex(index);
    }
    //자식노드가 양쪽에 있을 경우
    else
    {
        //두 우선순위를 비교해서 0보다 작은지 비교
        //우선순위가 높으면 값이 낮음
        if (ph->comp(ph->heapArr[GetLeftChildIndex(index)], ph->heapArr[GetRightChildIndex(index)]) < 0)
        {
            return GetRightChildIndex(index);
        }
        else
        {
            return GetLeftChildIndex(index);
        }
    }
}

//삽입
void HInsert(Heap *ph, HData data)
{
    //새로 추가되는 힙의 인덱스
    int index = ph->numOfData + 1;
    //위치를 찾아주는 while
    //인덱스가 1이면 바로 삽입하거나 루트이기 때문
    while (index != 1)
    {
        //우선순위가 힙의 부모보다 작을 경우
        if (ph->comp(data, (ph->heapArr[GetPartenIndex(index)])) > 0)
        {
            //부모와 자신의 위치를 바꿔주고 인덱스를 갱신해줌
            ph->heapArr[index] = ph->heapArr[GetPartenIndex(index)];
            index = GetPartenIndex(index);
        }
        else
        {
            //아니면 위치 찾음
            break;
        }
    }
    //현재 찾은 위치에 삽입 후 데이터 증가
    ph->heapArr[index] = data;
    ph->numOfData++;
}

//제거
HData HDelete(Heap *ph)
{
    //삭제할 노드의 데이터를 저장하고 제일 마지막의 노드값을 올려주기 위해 저장함.
    HData tempData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    //현재 루트이기 때문에 1로 설정하고 자식은 앞으로 교환해줌
    int targetIndex = 1;
    int childIndex;

    //루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문을 시작한다.
    //childIndex 가  0이 되면 멈춤
    while (childIndex = GetHipPriChildIndex(ph, targetIndex))
    {
        //자식의 우선순위가 낮을 경우 멈춤
        if (ph->comp(lastElem, ph->heapArr[childIndex]) >= 0)
        {
            break;
        }
        //목표인 인덱스(부모)와 자식 인덱스를 바꿔줌
        ph->heapArr[targetIndex] = ph->heapArr[childIndex];
        targetIndex = childIndex;
    }

    //목표한 인덱스에 제일 마지막의 원소를 삽입함.
    ph->heapArr[targetIndex] = lastElem;
    //삭제 했으니까 데이터 수 줄여줌.
    ph->numOfData--;
    return tempData;
}