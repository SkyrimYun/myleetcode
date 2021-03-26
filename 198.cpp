/*
有些时候显式的dp结构并没有必要
比如此题，直接两个指针滚动就可以了，速度会快一些
*/

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

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};
