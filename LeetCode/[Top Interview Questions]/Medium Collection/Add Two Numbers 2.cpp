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
// Memory   : 77.1MB   44.56%

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(), *temp = dummy;
        bool carry = false;
        while (l1 || l2)
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry)
            {
                sum++;
                carry = false;
            }

            if (sum >= 10)
            {
                carry = true;
                sum -= 10;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;
        }

        if (carry)
        {
            temp->next = new ListNode(1);
        }
        return dummy->next;
    }
};