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

// Runtime  : 0ms      100.00%
// Memory   : 19.5MB   62.69

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

// 0ms      100.00 %
// 16.8MB   94.42 %
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        deque<TreeNode *> lde, rde;
        TreeNode *lcurr = root->left;
        TreeNode *rcurr = root->right;

        while (lcurr || rcurr || !lde.empty() || !rde.empty())
        {
            while (lcurr)
            {
                lde.push_back(lcurr);
                lcurr = lcurr->left;
            }

            while (rcurr)
            {
                rde.push_back(rcurr);
                rcurr = rcurr->right;
            }

            if (lde.size() != rde.size())
                return false;

            lcurr = lde.back();
            rcurr = rde.back();

            lde.pop_back();
            rde.pop_back();

            if (lde.size() != rde.size())
                return false;

            if (lcurr->val != rcurr->val)
                return false;

            lcurr = lcurr->right;
            rcurr = rcurr->left;
        }
        return true;
    }
};