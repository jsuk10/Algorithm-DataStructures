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

using namespace std;

// Runtime  : 0 ms     100.00%
// Memory   : 21.9MB   75.38%

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
    bool isValidBST(TreeNode *root)
    {
        deque<TreeNode *> de;
        TreeNode *curr = root;
        TreeNode *pre = nullptr;
        while (curr || !de.empty())
        {
            while (curr)
            {
                de.push_back(curr);
                curr = curr->left;
            }

            curr = de.back();
            de.pop_back();

            if (curr && pre && curr->val <= pre->val)
            {
                return false;
            }

            pre = curr;
            curr = curr->right;
        }

        return true;
    }
};