/*
思路参考 206
明确定义之后把递归函数当作普通函数使用
针对链表，一般思路为，给定函数定义，把当前节点的下一个节点给到函数，根据返回值，在当前函数内加工返回值和当前节点已得到想要的结果
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
private:
    ListNode *successor = nullptr;
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }

        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == 1)
            return reverseN(head, n);

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    Solution s;
    s.reverseBetween(head, 2, 3);
}