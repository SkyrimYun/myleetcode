#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ret = INT32_MIN;
        sort(nums.begin(), nums.end());

        int first = 0, second = 0, third = 0;
        int towsum = 0, threesum = 0;
        int sz = nums.size();

        for (int i = 0; i < sz - 2; i++)
        {
            first = i;
            second = i + 1;
            third = sz - 1;
            towsum = target - nums[first];
            while (second < third)
            {
                threesum = nums[first] + nums[second] + nums[third];
                if (abs(target - threesum) < abs(target - ret))
                    ret = threesum;

                if (nums[second] + nums[third] > towsum)
                    third--;
                else if (nums[second] + nums[third] < towsum)
                    second++;
                else
                    return target;
            }
            while (i < sz - 2 && nums[i + 1] == nums[i])
                i++;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-1, 2, 1, -4};
    int ret = s.threeSumClosest(nums, 1);
    cout << ret;
}