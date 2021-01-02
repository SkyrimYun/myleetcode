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
    ListNode(int x, ListNode *n = nullptr) : val(x), next(n) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *p1 = head;
        ListNode *left_prev = left;
        ListNode *right_prev = right;
        while (p1 != nullptr)
        {
            if (p1->val < x)
            {
                left->next = p1;
                left = left->next;
            }
            else
            {
                right->next = p1;
                right = right->next;
            }
            p1 = p1->next;
        }
        right->next = nullptr;
        left->next = right_prev->next;
        return left_prev->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    Solution s;
    s.partition(head, 3);
}