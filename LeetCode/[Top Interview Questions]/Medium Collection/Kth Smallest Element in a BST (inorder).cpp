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
#include <queue>

using namespace std;

// Runtime  : 0ms           100.00%
// Memory   : 24.3MB        67.19%

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
    int ans = INT_MIN;

    void DFS(TreeNode *node, int &k)
    {
        if (ans != INT_MIN || node == nullptr)
        {
            return;
        }

        DFS(node->left, k);
        if (--k == 0)
        {
            ans = node->val;
        }
        DFS(node->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        DFS(root, k);
        return ans;
    }
};