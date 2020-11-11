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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *end = head;
        ListNode *nth = head;
        int count = 0;
        while (end->next != nullptr)
        {
            end = end->next;
            count++;
            if (count > n)
            {
                nth = nth->next;
            }
        }
        if (count == n - 1)
            return head->next;
        else
            nth->next = nth->next->next;

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3)));
    Solution s;
    cout << s.removeNthFromEnd(head, 3)->val;
}