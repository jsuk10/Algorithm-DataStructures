#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

// Runtime  : 0ms      100.00%
// Memory   : 22MB     46.53%

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
public:
    bool isBST(TreeNode *root, long min, long max)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= min || root->val >= max)
        {
            return false;
        }

        return isBST(root->right, root->val, max) && isBST(root->left, min, root->val);
    }

    bool isValidBST(TreeNode *root)
    {

        return isBST(root, LONG_MIN, LONG_MAX);
    }
};