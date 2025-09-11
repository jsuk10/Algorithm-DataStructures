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
// Memory   : 14.7MB        99.37%

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;

        if (root != nullptr)
        {
            q.push(root);
        }

        int count = -1;
        while (!q.empty())
        {
            count++;
            ans.push_back({});
            int num = q.size();
            for (int i = 0; i < num; ++i)
            {
                TreeNode *node;
                // 정방향 역방향
                node = q.front();
                q.pop();
                if (node == nullptr)
                {
                    continue;
                }

                ans[count].push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (count % 2 == 1)
            {
                reverse(ans[count].begin(), ans[count].end());
            }
        }

        return ans;
    }
};