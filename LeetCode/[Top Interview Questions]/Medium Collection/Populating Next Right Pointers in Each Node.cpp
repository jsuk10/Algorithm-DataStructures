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
// Memory   : 27.4MB        67.68%

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root == nullptr)
        {
            return nullptr;
        }

        q.push(root);

        while (!q.empty())
        {
            Node *Pre = nullptr;
            int tempSize = q.size();
            for (int i = 0; i < tempSize; i++)
            {
                Node *now = q.front();
                q.pop();
                if (Pre != nullptr)
                {
                    Pre->next = now;
                }
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
                Pre = now;
            }
        }
        return root;
    }
};