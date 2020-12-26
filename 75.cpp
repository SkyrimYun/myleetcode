/*
从左到右的遍历和从右到左的指针会有冲突
换过来的可能还是等于2或者0
1. 用while来处理值等于2的情况
2. 把值等于1的情况的处理放到2之后
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
    void sortColors(vector<int> &nums)
    {
        int point1 = 0;
        int point2 = nums.size() - 1;

        for (int i = 0; i <= point2; i++)
        {
            while (i <= point2 && nums[i] == 2)
            {
                swap(nums[point2], nums[i]);
                point2--;
            }
            if (nums[i] == 0)
            {
                swap(nums[point1], nums[i]);
                point1++;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 0};
    s.sortColors(nums);
}