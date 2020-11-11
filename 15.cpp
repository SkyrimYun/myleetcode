/*
和第一题towsum的主要区别在于twosum返回的是下标
而这里返回的直接是值
所以这里就不需要用哈希表存下标了
双指针可以都从开头走起，也可以一个在首一个在尾，向中间靠
反思：对于排序好的数组带来的性质理解的还不够透彻
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());

        int first = 0, second = 0, third = 0;
        int towsum = 0;
        int sz = nums.size();
        if (nums[0] > 0 || nums[sz - 1] < 0)
            return ret;

        for (int i = 0; i < sz - 2; i++)
        {
            if (nums[i] > 0)
                break;

            first = i;
            second = i + 1;
            third = nums.size() - 1;
            towsum = -nums[first];
            while (second < third)
            {
                if (nums[second] + nums[third] > towsum)
                    third--;
                else if (nums[second] + nums[third] < towsum)
                    second++;
                else
                {
                    ret.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
                    second++;
                    while (second < third && nums[second] == nums[second - 1])
                        second++;
                }
                while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                    i++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums{0};
    vector<vector<int>> ret = s.threeSum(nums);
    for (vector<int> ts : ret)
    {
        for (int t : ts)
            cout << t << ", ";
        cout << endl;
    }
}