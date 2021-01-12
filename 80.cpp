/*
迭代器 p1=p2 会让两个迭代器指向同一个元素，会导致相互影响
用erase(p1)之后，p1会自动指向被删掉元素的下一个元素
advance(iterator,pos) 把迭代器向前推进pos个位置
next(iterator,pos); prev(iterator,pos) 返回此迭代器前/后pos个位置的迭代器
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    // int removeDuplicates(vector<int> &nums)
    // {
    //     vector<int>::iterator p1 = nums.begin(), p2 = nums.begin();
    //     int count = 0;
    //     while (p1 != nums.end() && p2 != nums.end())
    //     {

    //         if (*p1 == *p2)
    //         {
    //             count++;
    //         }
    //         else
    //         {
    //             p1 = p2;
    //             count = 1;
    //         }

    //         if (count == 3)
    //         {
    //             nums.erase(p2);
    //             count--;
    //         }
    //         else
    //             p2++;
    //     }
    //     return nums.size();
    // }
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 3)
            return nums.size();
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2;
        vector<int>::iterator it3;
        int sz = nums.size();
        for (int i = 0; i < sz - 2; i++)
        {
            it2 = next(it1, 1);
            it3 = next(it1, 2);
            while (it3 != nums.end() && *it1 == *it2 && *it2 == *it3)
            {
                nums.erase(it3);
                sz--;
            }
            it1++;
        }
        return sz;
    }
};

int main()
{
    Solution s;
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << s.removeDuplicates(nums);
}