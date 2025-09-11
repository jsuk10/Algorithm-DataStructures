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

// Runtime  : 4ms           57.50%
// Memory   : 27.2MB        80.61%

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
    TreeNode *buildInternalTree(
        vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd)
    {
        // 종료 조건: 범위가 유효하지 않으면 nullptr
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // preorder 맨 앞이 루트
        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);

        // inorder에서 루트 위치 찾기
        auto rootIt = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, rootVal);
        int leftSize = rootIt - (inorder.begin() + inStart); // 왼쪽 서브트리 크기

        // 좌/우 서브트리 재귀 호출
        root->left = buildInternalTree(preorder, preStart + 1, preStart + leftSize,
                                       inorder, inStart, inStart + leftSize - 1);
        root->right = buildInternalTree(preorder, preStart + leftSize + 1, preEnd,
                                        inorder, inStart + leftSize + 1, inEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return nullptr;

        return buildInternalTree(preorder, 0, preorder.size() - 1,
                                 inorder, 0, inorder.size() - 1);
    }
};