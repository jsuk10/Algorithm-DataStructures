#include <stdio.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode **pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    //부모노드, 현재 노드, 새로운 노드
    BTreeNode *pNode = NULL;
    BTreeNode *cNode = *pRoot;
    BTreeNode *nNode = NULL;

    //자식 노드가 없어질때 까지 위치를 찾아줌
    while (cNode != NULL)
    {
        //데이터가 중복일 경우
        if (data == GetData(cNode))
            return;
        //자식 노드로 옮김.
        pNode = cNode;

        if (GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode();
    //nNode->data = data;
    SetData(nNode, data);
    //루트 노드가 아일 경우
    if (pNode != NULL)
    {
        if (data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    //루트일 경우
    else
    {
        *pRoot = nNode;
    }
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *tempNode = bst;
    BTData tempData;
    while (tempNode != NULL)
    {
        //if (tempNode->data = target)
        tempData = GetData(tempNode);
        if (tempData == target)
        {
            printf("탐색에 성공! \n키의 값: %d \n", tempData);
            return tempNode;
        }
        if (tempData < target)
            tempNode = GetRightSubTree(tempNode);
        else
            tempNode = GetLeftSubTree(tempNode);
    }

    printf("탐색 실패 \n");
    return NULL;
}
