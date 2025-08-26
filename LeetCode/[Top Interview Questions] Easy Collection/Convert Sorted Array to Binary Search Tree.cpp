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

// Runtime  : 1ms      76.83%
// Memory   : 22.9MB   81.61%

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
    TreeNode *MakeBST(vector<int> &nums, int startindex, int endindex)
    {
        if (startindex > endindex)
        {
            return nullptr;
        }
        if (startindex < 0 || endindex >= nums.size())
        {
            return nullptr;
        }
        int rootindex = (startindex + endindex) / 2;
        TreeNode *root = new TreeNode(nums[rootindex]);

        root->left = MakeBST(nums, startindex, rootindex - 1);
        root->right = MakeBST(nums, rootindex + 1, endindex);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return MakeBST(nums, 0, nums.size() - 1);
    }
};