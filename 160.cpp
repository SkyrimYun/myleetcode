#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <list>

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
private:
    unordered_set<ListNode *> ht;

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // pair<unordered_set<ListNode *>::iterator, bool> checkA;
        // pair<unordered_set<ListNode *>::iterator, bool> checkB;

        // while (headA)
        // {
        //     checkA = ht.insert(headA);
        //     if (!checkA.second)
        //         return headA;
        //     headA = headA->next;
        // }
        // while (headB)
        // {
        //     checkB = ht.insert(headB);
        //     if (!checkB.second)
        //         return headB;
        //     headB = headB->next;
        // }
        // return nullptr;

        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2)
        {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};