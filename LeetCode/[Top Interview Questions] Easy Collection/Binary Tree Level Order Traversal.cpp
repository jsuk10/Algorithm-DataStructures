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
// Memory   : 16.68    97.54%

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> answer;
        queue<TreeNode *> qu;

        qu.push(root);
        int count = 1;
        int vectorIndex = 0;
        answer.push_back(vector<int>());

        while (!qu.empty())
        {
            TreeNode *curr = qu.front();
            qu.pop();
            if (curr != nullptr)
            {
                answer[vectorIndex].push_back(curr->val);
                qu.push(curr->left);
                qu.push(curr->right);
            }

            if (--count == 0)
            {
                count = answer[vectorIndex].size() * 2;
                vectorIndex++;
                answer.push_back(vector<int>());
            }
        }

        while (answer.size() != 0 && answer.back().size() == 0)
        {
            answer.pop_back();
        }

        return answer;
    }
};