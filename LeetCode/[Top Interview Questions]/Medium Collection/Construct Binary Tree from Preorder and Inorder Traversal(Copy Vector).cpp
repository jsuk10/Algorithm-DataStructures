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

// Runtime  : 31ms          6.66%
// Memory   : 74.7MB        6.34%

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
    TreeNode *buildInternalTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() <= 0)
            return nullptr;

        if (preorder.size() == 1)
            return new TreeNode(preorder[0]);

        // 루트 노드를 찾는다. 전위 순회이므로 가장 앞이 루트
        TreeNode *Root = new TreeNode(preorder[0]);

        // 루트 노드 앞뒤로 나눠서 앞에는 좌측 뒤에는 우측으로 나눈다.
        auto BackRoot = find(inorder.begin(), inorder.end(), preorder[0]);
        int Size = BackRoot - inorder.begin(); // 루트의 위치 인덱스

        // 갯수 만큼 슬라이드
        vector<int> frontPreorderVector(preorder.begin() + 1, preorder.begin() + 1 + Size);
        vector<int> backPreorderVector(preorder.begin() + 1 + Size, preorder.end());

        // 갯수 만큼 슬라이드
        vector<int> frontInorderVector(inorder.begin(), inorder.begin() + Size);
        vector<int> backInorderVector(inorder.begin() + Size + 1, inorder.end());

        // 좌우 분할정복
        Root->left = buildInternalTree(frontPreorderVector, frontInorderVector);
        Root->right = buildInternalTree(backPreorderVector, backInorderVector);

        return Root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *Root = buildInternalTree(preorder, inorder);

        return Root;
    }
};