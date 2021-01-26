/*
141/142都是快慢指针 来检查是否有环
快指针一次跳两步，慢指针一次一步
比较指针可以不用管 p1->val == p2->val
直接 p1==p2 就行
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

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
    //哈希表
    // bool hasCycle(ListNode *head)
    // {
    //     unordered_set<ListNode *> map;
    //     while (head != nullptr)
    //     {
    //         if (map.count(head))
    //             return true;
    //         map.insert(head);
    //         head = head->next;
    //     }
    //     return true;
    // }

    //快慢指针
    bool hasCycle(ListNode *head)
    {
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2 != nullptr && p2->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;

            if (p1 == p2)
                return true;
        }
        return false;
    }
};