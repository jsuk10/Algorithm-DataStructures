#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <deque>
#include <stack>
#include <string>
#include <string_view>
#include <utility>

using namespace std;

// Runtime  : 0ms           100.00%
// Memory   : 27.4MB        67.68%

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *build(
        const vector<int> &preorder, const int preStart,
        const int inStart, const int inEnd,
        const unordered_map<int, int> &inorderIndex)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);

        const int ValueIndex = inorderIndex.at(rootVal);
        int leftSize = ValueIndex - inStart;

        // 좌/우 서브트리 재귀 호출 idx값을 중심으로 좌우로 나눈다.
        // 좌 [inStart, idx - 1]
        // 우 [idx + 1, inEnd]
        root->left = build(preorder, preStart + 1, inStart, ValueIndex - 1, inorderIndex);
        root->right = build(preorder, preStart + 1 + leftSize, ValueIndex + 1, inEnd, inorderIndex);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // inorder 값 -> 인덱스 맵
        // Find 코스트를 아끼기 위해 unordered_map사용
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, 0, 0, inorder.size() - 1, inorderIndex);
    }
};