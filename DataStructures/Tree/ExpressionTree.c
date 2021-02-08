#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Stack/ListStack/CustomListBaseStack.c"
#include "BinaryTreeTraverse.c"
#include "ExpressionTree.h"

BTreeNode *MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode *tempNode;

    int expLen = strlen(exp);

    StackInit(&stack);

    for (int i = 0; i < expLen; i++)
    {
        tempNode = MakeBTreeNode();

        //숫자인지 판단해주는 함수
        if (isdigit(exp[i]))
        {
            //데이터가 숫자면 0을빼서 저장
            SetData(tempNode, (exp[i] - '0'));
        }
        //연산자면 좌우노드에 할당해주고 데이터 세팅해줌(트리 제작)
        else
        {
            MakeRightSubTree(tempNode, (BTreeNode *)SPop(&stack));
            MakeLeftSubTree(tempNode, (BTreeNode *)SPop(&stack));
            SetData(tempNode, exp[i]);
        }
        //스텍에 노드/트리를 삽입해줌 (if에선 노드, else에선 트리)
        SPush(&stack, (Data)tempNode);
    }
    //마지막에 트리가 스텍에 들어 있으므로 그것을 리턴해줌
    return (BTreeNode *)SPop(&stack);
}

int EvaluateExpTree(BTreeNode *bt)
{
    int op1, op2;
    //탈출 조건
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);
    //자식노드를 얻어옴
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    //부모 노드의 연산자 얻어옴
    switch (GetData(bt))
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;

    default:
        return 0;
    }
}

void ShowPrefixTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowData);
}
void ShowInfixTypeExp(BTreeNode *bt)
{
    InorderTraverse(bt, ShowData);
}
void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowData);
}