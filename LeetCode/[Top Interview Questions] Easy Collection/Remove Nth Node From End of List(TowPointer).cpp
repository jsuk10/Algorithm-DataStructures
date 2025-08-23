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
// Memory   : 14.9MB   91.66

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp1 = head;
        ListNode *temp2 = head;

        while (n-- != 0)
        {
            temp1 = temp1->next;
        }

        if (temp1 == nullptr)
        {
            head = head->next;
            return head;
        }

        while (temp1->next != nullptr)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp2->next = temp2->next->next;
        return head;
    }
};