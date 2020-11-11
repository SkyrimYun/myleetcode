/*
在链表操作中
使用一个在第一个node之前的node
并返回这个node的next
是一个常用技巧
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *ret = new ListNode(); // node before first node
        ListNode *cur = ret;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val > l2->val)
            {
                cur->next = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        while (l1 != nullptr)
        {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        return ret->next; // return its next node
    }
};