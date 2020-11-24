/*
注意二分法的起始状态和搜索空间
1. start和end为指向第一个和最后一个元素
2. while的条件为start<=end，注意这个等号
3. 下一轮的搜索空间不要把middle包含在里面

针对这个题，相比于基础二分法，主要是在下一轮进入左边还是右边有更多的条件来决定
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int sz = nums.size();
        int middle = sz / 2;
        int start = 0;
        int end = sz - 1;
        while (start <= end)
        {
            if (nums[middle] == target)
                return middle;

            if (nums[middle] >= nums[start])
            {
                if (target < nums[middle] && target >= nums[start])
                    end = middle - 1;
                else
                    start = middle + 1;
            }
            else
            {
                if (target > nums[middle] && target <= nums[end])
                    start = middle + 1;
                else
                    end = middle - 1;
            }
            middle = (start + end) / 2;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{6, 7, 8, 9, 1, 2, 3, 4, 5};
    Solution s;
    cout << s.search(nums, 8);
}