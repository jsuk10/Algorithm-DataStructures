#include <stdio.h>
#include "BinaryTree.h"
#include "BinartTreeTraverse.h"
#include "BinartTreeTraverse.c"

int main(void)
{
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();
	BTreeNode *bt5 = MakeBTreeNode();
	BTreeNode *bt6 = MakeBTreeNode();
	BTreeNode *bt7 = MakeBTreeNode();
	BTreeNode *bt8 = MakeBTreeNode();
	BTreeNode *bt9 = MakeBTreeNode();

	SetData(bt1, 1); //a
	SetData(bt2, 2); //b
	SetData(bt3, 3); //c
	SetData(bt4, 4); //d
	SetData(bt5, 5); //e
	SetData(bt6, 6); //f
	SetData(bt7, 7); //g
	SetData(bt8, 8); //h
	SetData(bt9, 9); //i

	//lv 0
	MakeLeftSubTree(bt6, bt2);
	MakeRightSubTree(bt6, bt7);

	//lv 1
	MakeLeftSubTree(bt2, bt1);
	MakeRightSubTree(bt2, bt4);
	MakeRightSubTree(bt7, bt9);

	//lv 2
	MakeLeftSubTree(bt4, bt3);
	MakeRightSubTree(bt4, bt5);
	MakeLeftSubTree(bt9, bt8);

	printf("Preorder\n");
	PreorderTraverse(bt6, ShowData);
	printf("\n");

	printf("Inorder\n");
	InorderTraverse(bt6, ShowData);
	printf("\n");

	printf("Postorder\n");
	PostorderTraverse(bt6, ShowData);

	return 0;
}