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

// Runtime  : 0ms      100.00%
// Memory   : 77MB   91.93%

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
        ListNode *lr = l1, *ll = l2, *Head = nullptr, *next = nullptr;
        bool carry = false;
        while (lr || ll)
        {
            int sum = 0;

            if (lr != nullptr)
            {
                sum += lr->val;
                lr = lr->next;
            }

            if (ll != nullptr)
            {
                sum += ll->val;
                ll = ll->next;
            }

            if (carry)
            {
                sum++;
                carry = false;
            }

            if (sum >= 10)
            {
                sum -= 10;
                carry = true;
            }

            ListNode *temp = new ListNode(sum);
            if (Head == nullptr)
            {
                Head = temp;
                next = temp;
            }
            else
            {
                next->next = temp;
                next = temp;
            }
        }

        if (carry)
        {
            next->next = new ListNode(1);
        }

        return Head;
    }
};