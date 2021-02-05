#ifndef __BINARY_TREE_ADDCHANGE_H__
#define __BINARY_TREE_ADDCHANGE_H__
#include "BinaryTreeTraverse.h"

// 왼쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode *RemoveLeftSubTree(BTreeNode *bt);

// 오른쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode *RemoveRightSubTree(BTreeNode *bt);

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다.
void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다.
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif