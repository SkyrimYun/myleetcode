#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//还可以用递归的办法做
// class Solution
// {
// public:
//     ListNode *swapPairs(ListNode *head)
//     {
//         ///终止条件为所有都交换完了的链表
//         if (head == NULL || head->next == NULL)
//             return head;
//         ///递归单元内两个节点做交换
//         //定义一个p结点为head->next(该递归单元内第二个节点)
//         ListNode *p = head->next;
//         //记录第三个节点同时也是下一次递归的head
//         ListNode *temp = p->next;
//         //使此单元内第二个节点指向第一个节点，即交换位置
//         p->next = head;
//         //交换完成后的head应指向下一次单元返回的头节点
//         head->next = swapPairs(temp);
//         //返回该单元的头节点
//         return p;
//     }
// };

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *first = head;
        ListNode *second;
        ListNode *third;
        ListNode *prev;
        while (first != nullptr && first->next != nullptr)
        {
            second = first->next;
            third = second->next;
            second->next = first;
            first->next = third;
            if (first != head)
                prev->next = second;
            else
                head = second;
            prev = first;
            first = third;
        }
        return head;
    }
};