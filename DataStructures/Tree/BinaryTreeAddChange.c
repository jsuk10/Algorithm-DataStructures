#include <stdio.h>
#include "BinaryTreeTraverse.c"
#include "BinaryTreeAddChange.h"

// 왼쪽 자식 연결을 끊고 왼쪽 자식 반환
BTreeNode *RemoveLeftSubTree(BTreeNode *bt)
{
    BTreeNode *tempNode;
    if (bt != NULL)
    {
        tempNode = bt->left;
        bt->left = NULL;
    }
    return tempNode;
}

// 오른쪽 자식의 연결을 끊고 오른쪽 자식 반환
BTreeNode *RemoveRightSubTree(BTreeNode *bt)
{
    BTreeNode *tempNode;
    if (bt != NULL)
    {
        tempNode = bt->right;
        bt->right = NULL;
    }
    return tempNode;
}

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다.
void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->left = sub;
}

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다.
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->right = sub;
}