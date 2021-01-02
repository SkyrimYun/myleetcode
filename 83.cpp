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
        if (head == nullptr)
            return head;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                p1->next = p2;
                p1 = p2;
            }
            p2 = p2->next;
            if (p2 == nullptr)
                p1->next = nullptr;
        }
        return head;
    }
};