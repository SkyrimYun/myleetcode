/*
三指针
核心在于 p2=p3意味着没有重复数字，此时更新p1
        p2!=p3意味着重复数字，此时只更新p1->next，以防p3此时指向的数字仍然会有后续重复
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p1 = new ListNode(0);
        p1->next = head;
        head = p1;
        ListNode *p2, *p3;
        while (p1->next != nullptr)
        {
            p2 = p3 = p1->next;
            while (p3->next != nullptr && p3->next->val == p3->val)
                p3 = p3->next;
            if (p3 == p2)
                p1 = p1->next;
            else
                p1->next = p3->next;
        }
        return head->next;
    }
};