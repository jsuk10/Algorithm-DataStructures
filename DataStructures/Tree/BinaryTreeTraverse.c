#include <stdio.h>
#include "BinaryTree.c"
#include "BinaryTreeTraverse.h"

void ShowData(BTData data)
{
	printf("%d ", data);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}