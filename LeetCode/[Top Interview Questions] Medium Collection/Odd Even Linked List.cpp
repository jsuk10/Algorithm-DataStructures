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

// Runtime  : 0ms      100%
// Memory   : 16MB     ???%

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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *dummy1 = new ListNode(), *temp = dummy1;
        ListNode *dummy2 = new ListNode(), *temp2 = dummy2;
        bool even = false;
        while (head != nullptr)
        {
            if (even)
            {
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            else
            {
                temp2->next = new ListNode(head->val);
                temp2 = temp2->next;
            }
            even = !even;
            head = head->next;
        }
        temp2->next = dummy1->next;
        return dummy2->next;
    }
};