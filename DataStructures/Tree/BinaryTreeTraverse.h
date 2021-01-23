#ifndef __BINARY_TREETRAVER_H__
#define __BINARY_TREETRAVER_H__
#include "BinaryTree.h"

typedef void VisitFuncPtr(BTData data);

void ShowData(BTData data);

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);
#endif