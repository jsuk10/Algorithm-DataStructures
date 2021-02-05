#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinarySearchTree.c"

int main(void)
{
    //트리
    BTreeNode *bstRoot;
    //서칭된 노드
    BTreeNode *sNode;

    //초기화
    BSTMakeAndInit(&bstRoot);
    //삽입
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    //	BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);
    //	BSTInsert(&bstRoot, 7);

    //노드 탐색
    sNode = BSTSearch(bstRoot, 1);
    // if (sNode == NULL)
    //     printf("탐색 실패 \n");
    // else
    //     printf("탐색에 성공! \n키의 값: %d \n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 4);

    sNode = BSTSearch(bstRoot, 6);

    sNode = BSTSearch(bstRoot, 7);

    return 0;
}