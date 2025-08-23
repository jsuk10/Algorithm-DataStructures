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
// Memory   : 13.6MB   ??

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
    ListNode *reverseNode(ListNode *node)
    {
        // 엔드포인트, 끌까지 갈 경우
        if (node == nullptr || node->next == nullptr)
            return node;
        ListNode *newHead = reverseNode(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverseNode(head);
    }
};