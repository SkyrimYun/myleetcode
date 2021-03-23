/*
有点意思的一题
此题中，当前位置的最优解未必是由前一个位置的最优解转移得到的
需要考虑当前数字的正负
于是储存两个dp状态变量，一个储存以此结尾的最大乘积，一个储存以此结尾的最小乘积
这样就能够综合考虑正负带来的最大乘积
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

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> maxp(nums.size());
        vector<int> minp(nums.size());
        maxp[0] = minp[0] = nums[0];
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int maxpp = maxp[i - 1] * nums[i];
            int minpp = minp[i - 1] * nums[i];
            maxp[i] = max(maxpp, max(minpp, nums[i]));
            minp[i] = min(maxpp, min(minpp, nums[i]));
            ret = max(ret, maxp[i]);
        }
        return ret;
    }
};