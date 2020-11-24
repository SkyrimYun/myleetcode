#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int sz = nums.size();
        int middle = sz / 2;
        int start = 0;
        int end = sz - 1;
        while (start <= end)
        {
            if (nums[middle] == target)
                return middle;

            if (target < nums[middle])
                end = middle - 1;
            else if (target > nums[middle])
                start = middle + 1;

            middle = (start + end) / 2;
        }
        return start;
    }
};

int main()
{
    vector<int> nums{1, 3, 4, 5, 6, 7, 8, 8, 8, 8, 9};
    Solution s;
    cout << s.searchInsert(nums, 10);
}