#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        if (nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());

        int first = 0, second = 0, third = 0, fouth = 0;
        int towsum = 0;
        int sz = nums.size();

        for (int i = 0; i < sz - 3; i++)
        {
            first = i;
            for (int j = i + 1; j < sz - 2; j++)
            {
                second = j;
                third = j + 1;
                fouth = nums.size() - 1;
                towsum = target - nums[first] - nums[second];
                while (third < fouth)
                {
                    if (nums[fouth] + nums[third] > towsum)
                        fouth--;
                    else if (nums[fouth] + nums[third] < towsum)
                        third++;
                    else
                    {
                        ret.emplace_back(vector<int>{nums[first], nums[second], nums[third], nums[fouth]});
                        third++;
                        while (third < fouth && nums[third] == nums[third - 1])
                            third++;
                    }
                }
                while (j < sz - 2 && nums[j + 1] == nums[j])
                    j++;
            }
            while (i < sz - 3 && nums[i + 1] == nums[i])
                i++;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, -2, -5, -4, -3, 3, 3, 5};
    cout << s.fourSum(nums, -11).size();
}