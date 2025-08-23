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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        if (list1->val >= list2->val)
        {
            head = tail = list2;
            list2 = list2->next;
        }
        else
        {
            head = tail = list1;
            list1 = list1->next;
        }

        while (list1 && list2)
        {
            if (list1->val >= list2->val)
            {
                tail->next = list2;
                list2 = list2->next;
            }
            else
            {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }

        // 남은 부분 연결.
        tail->next = list1 ? list1 : list2;

        return head;
    }
};