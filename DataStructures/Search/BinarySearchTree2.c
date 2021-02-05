#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot)
{
    *pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode *bst)
{
    return GetData(bst);
}

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BTreeNode *pNode = NULL;   // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *nNode = NULL;   // new node

    // 새로운 노드가 추가될 위치를 찾는다.
    while (cNode != NULL)
    {
        if (data == GetData(cNode))
            return; // 키의 중복을 허용하지 않음

        pNode = cNode;

        if (GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    // pNode의 서브 노드에 추가할 새 노드의 생성
    nNode = MakeBTreeNode(); // 새 노드의 생성
    SetData(nNode, data);    // 새 노드에 데이터 저장

    // pNode의 서브 노드에 새 노드를 추가
    if (pNode != NULL) // 새 노드가 루트 노드가 아니라면,
    {
        if (data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else // 새 노드가 루트 노드라면,
    {
        *pRoot = nNode;
    }
}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = bst; // current node
    BSTData cd;             // current data

    while (cNode != NULL)
    {
        cd = GetData(cNode);

        if (target == cd)
            return cNode;
        else if (target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;
}

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다.
BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target)
{
    //가상 루트 노드, 부모 노드, 현재 노드, 삭제 노드(반환)를 의미함
    BTreeNode *pVRoot = MakeBTreeNode(); // 가상 루트 노드;

    //연결을 위해 선언
    BTreeNode *pNode = pVRoot;
    //찾기위해 선언
    BTreeNode *cNode = *pRoot;
    //리턴값 저장
    BTreeNode *dNode;

    //루트 노드를 pVroot가 가르키는 오른쪽 노드가 되게 함.
    //즉 루트 노드를 pVroot오른쪽에 연결
    //이는 루트 노드를 삭제할 경우를 고려해서 일반화 하였음.
    ChangeRightSubTree(pVRoot, *pRoot);

    while (cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;

        if (target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    //찾지 못한다면.
    if (cNode == NULL)
    {
        return NULL;
    }

    //찾은 노드 대입
    dNode = cNode;

    //case 1 : 삭제 대상이 단말 노드인경우
    if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if (GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    //case 2 : 삭제 대상이 하나의 자식 노드를 가질 경우
    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        //삭제 대상의 자식 노드
        BTreeNode *dcNode;
        //왼쪽을 가질 경우
        if (GetLeftSubTree(dNode) != NULL)
        {
            dcNode = GetLeftSubTree(dNode);
        }
        //오른쪽을 가질 경우
        else
        {
            dcNode = GetRightSubTree(dNode);
        }
        //삭제할 노드가 부모의 왼쪽인지 오른쪽인지 확인
        if (GetLeftSubTree(pNode) == dNode)
        {
            ChangeLeftSubTree(pNode, dcNode);
        }
        else
        {
            ChangeRightSubTree(pNode, dcNode);
        }
    }
    //case 3 : 두개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode *tempNode = GetRightSubTree(dNode);
        BTreeNode *tempParentNode = dNode;
        int tempData;

        //삭제 대상의 대체 노드를 찾음
        while (GetLeftSubTree(tempNode) != NULL)
        {
            tempParentNode = tempNode;
            tempNode = GetLeftSubTree(tempNode);
        }

        //대체 노드에 저장된 값을 삭제할 노드에 대입한다.
        tempData = GetData(tempNode);
        SetData(dNode, GetData(tempNode));

        //삭제 노드가 루트일 경우 처리
        if (GetLeftSubTree(tempNode) == tempNode)
            ChangeLeftSubTree(tempParentNode, GetRightSubTree(tempNode));
        else
            ChangeRightSubTree(tempParentNode, GetRightSubTree(tempNode));

        dNode = tempNode;
        SetData(dNode, tempData);
    }

    if (GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);
    free(pVRoot);
    return dNode;
}

void ShowIntData2(int data)
{
    printf("%d ", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowAll(BTreeNode *bst)
{
    InorderTraverse(bst, ShowIntData2);
}
