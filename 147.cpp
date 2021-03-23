/*
insertion sort
//平均时间复杂度  O(n^{2})
//最坏时间复杂度  O(n^{2})
//最优时间复杂度  O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>

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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *vh = new ListNode(0, head);

        ListNode *prev = head;
        ListNode *cur = head->next;
        while (cur != nullptr)
        {
            if (prev->val <= cur->val)
            {
                prev = cur;
                cur = cur->next;
            }
            else
            {
                ListNode *cop = vh;
                while (cop->next->val < cur->val)
                    cop = cop->next;
                ListNode *temp = cop->next;
                ListNode *curN = cur->next;
                cop->next = cur;
                cur->next = temp;
                cur = curN;
                prev->next = cur;
            }
        }
        return vh->next;
    }
};