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
// Memory   : 15.2MB        48.04%

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
    void bfs(TreeNode *root, vector<vector<TreeNode *>> &arry, int depth)
    {
        if (root == nullptr)
        {
            return;
        }
        if (arry.size() <= depth)
        {
            arry.push_back({});
        }
        arry[depth].push_back(root);
        bfs(root->left, arry, depth + 1);
        bfs(root->right, arry, depth + 1);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<vector<TreeNode *>> node;
        bfs(root, node, 0);

        for (int i = 0; i < node.size(); i++)
        {
            if (i % 2 == 1)
            {
                reverse(node[i].begin(), node[i].end());
            }

            ans.push_back({});

            for (auto b : node[i])
            {
                ans[i].push_back(b->val);
            }
        }
        return ans;
    }
};