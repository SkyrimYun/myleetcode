/*
二分法的核心还是在于判断target到底在左半边还是右半边
像这种变种题，万变不离其宗，用更细致的条件来决定下一轮进左还是进右
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
    bool search(vector<int> &nums, int target)
    {
        int sz = nums.size();
        int middle = sz / 2;
        int start = 0;
        int end = sz - 1;
        while (start <= end)
        {
            while (start < end && nums[start] == nums[end])
            {
                start++;
                middle = (start + end) / 2;
            }
            if (start > end)
                return false;

            if (nums[middle] == target)
                return true;

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
        return false;
    }
};

int main()
{
    vector<int> nums{1, 3, 1, 1};
    Solution s;
    cout << s.search(nums, 3);
}