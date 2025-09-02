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

// Runtime  : 54ms          11.77%
// Memory   : 23.7MB        5.70%

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
    void inOrderTraversal(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;

        // note.jsuk10 중위가 아닐경우 순서만 바꿔주면 됨.

        inOrderTraversal(root->left, v);
        v.push_back(root->val);
        inOrderTraversal(root->right, v);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> a;
        inOrderTraversal(root, a);

        return a;
    }
};