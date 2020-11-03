/*
initialize the list with "the one before the first one (-1)" and return the next one (which is the real first one)
in order to aviod initilized next ptr
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = new ListNode(-1); //!!!
        ListNode *ret = sum;
        int add = 0;
        bool addone = false;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr)
            {
                add += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                add += l2->val;
                l2 = l2->next;
            }
            add = addone ? add + 1 : add;
            addone = add >= 10 ? true : false;
            sum->next = new ListNode(add % 10); //!!!!

            sum = sum->next;

            add = 0;
        }

        if (addone)
            sum->next = new ListNode(1);

        return ret->next; //!!!!
    }
};

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));

    ListNode *sum = s.addTwoNumbers(l1, l2);
}