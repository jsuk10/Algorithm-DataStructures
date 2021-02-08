#ifndef __AVL__REBALANCE_H__
#define __AVL__REBALANCE_H__

#include "../Tree/BinaryTreeAddChange.h"
#include "../Tree/BinaryTreeAddChange.c"
#include "BinarySearchTree2.h"
#include "BinarySearchTree2.c"

// LL 회전
BTreeNode *RotateLL(BTreeNode *bst);

// RR 회전
BTreeNode *RotateRR(BTreeNode *bst);

// RL 회전
BTreeNode *RotateRL(BTreeNode *bst);

// LR 회전
BTreeNode *RotateLR(BTreeNode *bst);

//트리의 높이를 계산하여 반환함
int GetHight(BTreeNode *bts);

//트리의 균형인수를 계산하여 반환함
int GetHightDiff(BTreeNode *bts);

// 트리의 균형을 잡는다.
BTreeNode *Rebalance(BTreeNode **pRoot);
#endif