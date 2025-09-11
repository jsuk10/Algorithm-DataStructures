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

// Runtime  : 54ms          11.77%
// Memory   : 23.7MB        5.70%

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp = headA;
        ListNode *temp2 = headB;
        while (temp != temp2)
        {
            temp = temp->next;
            temp2 = temp2->next;

            if (temp == temp2)
                return temp;
            if (!temp)
                temp = headB;
            if (!temp2)
                temp2 = headA;
        }
        return temp;
    }
};