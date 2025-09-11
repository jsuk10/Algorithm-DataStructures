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

// 0 ms     100.00%
// 124.4    37.67%

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        string s = "";
        while (head != nullptr)
        {
            s += (head->val + '0');
            head = head->next;
        }
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }

        return true;
    }
};