#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>

using namespace std;

// Runtime  : 0ms      100.00%
// Memory   : 19.5MB   62.69

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 6ms      90.55 %
// 11.7MB   79.80 %
// -10^5 <= val <= 10^5

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        while (head != nullptr && head->next != nullptr)
        {
            if (head->val == INT_MAX)
            {
                return true;
            }
            head->val = INT_MAX;
            head = head->next;
        }
        return false;
    }
};