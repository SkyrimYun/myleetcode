/*
！！！不要跳进递归！！！
"你的小脑袋能压几个栈呀？"
而是要根据函数定义，来弄清楚这段代码会产生什么结果
reverseList(head)定义：给定head node，返回翻转后的第一个node
递归调用的时候只考虑参数和返回即可，不要跳入，当成黑匣子就好，不要考虑其实现
就像“我有一个神奇函数能返回翻转后list的第一个node，用就行，我不需要知道是怎么实现的”
以此为基础，再考虑我拿到翻转后头部node之后接下来该怎么处理
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
    ListNode(int x, ListNode *n = nullptr) : val(x), next(n) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};