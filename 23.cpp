/*
合并多个有序链表 = n*合并两个链表
如何更有效率？
    分治
    （0，1） （2，3） （4，5） （6，7）
          （0，3）       （4，7）
                 （0，7）
    用递归分解数组，合并，再组合起来
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
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if ((!l1) || (!l2))
            return l1 ? l1 : l2;
        ListNode *ret = new ListNode(); // node before first node
        ListNode *cur = ret;
        while (l1 && l2)
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
        cur->next = l1 ? l1 : l2;
        return ret->next; // return its next node
    }

    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};