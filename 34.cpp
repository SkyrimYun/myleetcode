#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int sz = nums.size();
        int middle = sz / 2;
        int start = 0;
        int end = sz - 1;
        while (start <= end)
        {
            if (nums[middle] == target)
            {
                int ind1 = middle, ind2 = middle;
                while (ind1 > 0 && nums[ind1 - 1] == target)
                    ind1--;
                while (ind2 < sz - 1 && nums[ind2 + 1] == target)
                    ind2++;
                return vector<int>{ind1, ind2};
            }

            if (target < nums[middle])
                end = middle - 1;
            else if (target > nums[middle])
                start = middle + 1;

            middle = (start + end) / 2;
        }
        return vector<int>{-1, -1};
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 8, 9};
    Solution s;
    cout << s.searchRange(nums, 8)[0] << s.searchRange(nums, 8)[1];
}