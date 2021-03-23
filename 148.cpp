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
private:
    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
            return head;
        if (head->next == tail) //只有一个节点
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *vh = new ListNode(0);
        ListNode *temp = vh;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val >= head2->val)
            {
                temp->next = head2;
                head2 = head2->next;
            }
            else
            {
                temp->next = head1;
                head1 = head1->next;
            }
            temp = temp->next;
        }
        temp->next = head1 ? head1 : head2;
        return vh->next;
    }

    //在链表的前n个节点切掉，断链，并返回后半部分表头
    ListNode *cut(ListNode *head, int n)
    {
        ListNode *cur = head;
        while (--n && cur)
            cur = cur->next;
        if (!cur)
            return cur;
        ListNode *next = cur->next;
        cur->next = nullptr;
        return next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        // 迭代法，但空间复杂的不为O(1)
        //return sortList(head, nullptr);

        // Bottom-up
        ListNode *vh = new ListNode(0);
        vh->next = head;
        int size = 0;
        ListNode *cur = head;
        while (cur)
        {
            cur = cur->next;
            size++;
        }

        for (int length = 1; length < size; length *= 2)
        {
            ListNode *cur = vh->next;
            ListNode *tail = vh;

            while (cur)
            {
                auto left = cur;
                auto right = cut(left, length);
                cur = cut(right, length);
                tail->next = merge(left, right);
                while (tail->next)
                    tail = tail->next;
            }
        }
        return vh->next;
    }
};