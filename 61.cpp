#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        int sz = 1;
        ListNode *p1 = head;
        while (p1->next != nullptr)
        {
            p1 = p1->next;
            sz++;
        }
        k = k % sz;
        if (k == 0)
            return head;
        ListNode *p2 = head;
        for (int i = 0; i < sz - k - 1; i++)
            p2 = p2->next;
        ListNode *ret = p2->next;
        p2->next = nullptr;
        p1->next = head;
        return ret;
    }
    // ListNode *rotateRight(ListNode *head, int k)
    // {
    //     if (head == nullptr)
    //         return head;

    //     ListNode *p1 = head;
    //     int sz = 0;
    //     while (p1 != nullptr)
    //     {
    //         sz++;
    //         p1 = p1->next;
    //     }
    //     p1 = head;
    //     for (int i = 0; i < (sz - (k % sz) - 1); i++)
    //     {
    //         p1 = p1->next;
    //     }

    //     ListNode *p2 = p1;
    //     ListNode *ret = p1;
    //     if (p1->next == nullptr)
    //         return head;
    //     else
    //         ret = p1->next;

    //     while (p2->next != nullptr)
    //         p2 = p2->next;

    //     p1->next = nullptr;
    //     p2->next = head;
    //     return ret;
    // }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    cout << s.rotateRight(head, 0);
}