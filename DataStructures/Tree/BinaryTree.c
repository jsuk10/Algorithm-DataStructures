#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BTData GetData(BTreeNode *bt)
{
    return bt->data;
}
void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

//아래 두개 예외처리 안해줌 ㅠ
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->left != NULL)
        DeleteTree(main->left);
    main->left = sub;
}
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL)
        DeleteTree(main->right);
    main->right = sub;
}

void DeleteTree(BTreeNode *main)
{

    if (main == NULL)
        return;

    DeleteTree(main->left);
    DeleteTree(main->right);
    free(main);
}