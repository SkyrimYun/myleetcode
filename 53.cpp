/*
Dynamic Porgramming

dp[i]表示以i结尾的子串里最大的连续和是多少
转移方程可以理解为，在考虑nums[i]到底是加入以i-1结尾的最大连续和子串中，还是自己另外开启一个新的子串
只需要看dp[i-1]是不是大于0即可

注意，在dp[]中一般保存的是“候选的结果”。比如此题中就是所有以i结尾的最大子串合，然后我们在从中找到和最大的那一个
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxsub = nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int pos = 1; pos < nums.size(); pos++)
        {
            dp[pos] = max(nums[pos], dp[pos - 1] + nums[pos]);
            maxsub = max(maxsub, dp[pos]);
        }
        return maxsub;
    }
};

int main()
{
    vector<int> nums{-9, -3, 2, 8, -6, 5, 2, -3, -9, 5, -5, -1, 9, -7, 4, 0, 1, 7, -4};
    Solution s;
    cout << s.maxSubArray(nums);
}