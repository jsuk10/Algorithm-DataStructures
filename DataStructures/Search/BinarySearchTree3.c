#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree3.h"

// LL 회전
BTreeNode *RotateLL(BTreeNode *bst)
{
    //부모 노드
    //오른쪽 자식노드가 될예정
    BTreeNode *pNode = bst;
    //왼쪽 자식
    //노드 루트가 될 노드임
    BTreeNode *cNode = GetLeftSubTree(pNode);

    //자식 노드에 오른쪽에 붙은 것을 부모의 왼쪽에 붙여줌.
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    //자식 노드에 부모를 오른쪽에 붙여줌.
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}

// RR 회전
BTreeNode *RotateRR(BTreeNode *bst)
{
    //부모 노드
    //왼쪽 자식 노드가 될 예정
    BTreeNode *pNode = bst;
    //오른쪽 자식
    //노드 루트가 될 노드임
    BTreeNode *cNode = GetRightSubTree(pNode);

    //자식 노드에 왼쪽에 붙은 것을 부모의 오른쪽에 붙여줌.
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    //자식 노드에 부모를 왼쪽에 붙여줌.
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

// RL 회전
BTreeNode *RotateRL(BTreeNode *bst)
{
    //부모노드
    //왼쪽 자식 노드가 될 예정
    BTreeNode *pNode = bst;
    //부모의 오른쪽 자식 노드
    //부모 노드가 될 예정
    BTreeNode *cNode = GetRightSubTree(pNode);

    //부모의 왼쪽 서브 트리를 RR회전하여 재 배치
    //LL회전 부분
    ChangeLeftSubTree(pNode, RotateLL(cNode));

    //RR회전을 통해 벨런스 맞는 노드 리턴
    return RotateRR(pNode);
}

// LR 회전
BTreeNode *RotateLR(BTreeNode *bst)
{
    //부모노드
    //오른쪽 자식 노드가 될 예정
    BTreeNode *pNode = bst;
    //부모의 왼쪽 자식 노드
    //부모 노드가 될 예정
    BTreeNode *cNode = GetLeftSubTree(pNode);

    //부모의 왼쪽 서브 트리를 RR회전하여 재 배치
    //RR회전 부분
    ChangeLeftSubTree(pNode, RotateRR(cNode));

    //LL회전을 통해 벨런스 맞는 노드 리턴
    return RotateLL(pNode);
}

//트리의 높이를 반환함
int GetHight(BTreeNode *bst)
{
    int leftH;
    int rightH;

    if (bst == NULL)
    {
        return 0;
    }

    leftH = GetHight(GetLeftSubTree(bst));
    rightH = GetHight(GetRightSubTree(bst));

    return (leftH > rightH) ? (leftH + 1) : (rightH + 1);
}

//트리의 균형인수를 계산하여 반환함
int GetHightDiff(BTreeNode *bst)
{

    int leftH;
    int rightH;

    if (bst == NULL)
    {
        return 0;
    }

    leftH = GetHight(GetLeftSubTree(bst));
    rightH = GetHight(GetRightSubTree(bst));
    return leftH - rightH;
}

// 트리의 균형을 잡는다.
BTreeNode *Rebalance(BTreeNode **pRoot)
{
    //균형인수 계산
    int hDiff = GetHightDiff(*pRoot);

    //균형인수가 2 이상일 경우
    //즉 왼쪽 서브트리가 큰 LL/LR상태
    if (hDiff > 1)
    {
        //LL상태
        if (GetHightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(pRoot);
        //LR상태
        else
            *pRoot = RotateLR(pRoot);
    }
    //균형인수가 -1이하일 경우
    //즉 오른쪽 서브트리가 큰 RR/RL상태
    else if (hDiff < -1)
    {
        //RR상태
        if (GetHightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(pRoot);
        //RL상태
        else
            *pRoot = RotateRL(*pRoot);
    }
    // -1 <= hDiff <= 1일 경우 균형트리임
    
    return *pRoot;
}