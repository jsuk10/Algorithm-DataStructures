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
// Memory   : 15.2MB   ???

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
        vector<ListNode *> v;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            v.push_back(temp);
            temp = temp->next;
        }

        int target = v.size() - n;
        if (target == 0)
        {
            head = head->next;
            return head;
        }
        else
        {
            v[target - 1]->next = v[target]->next;
            return head;
        }
    }
};