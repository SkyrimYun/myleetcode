/*
贪心算法
局部最优=全局最优

nums中每一个元素能跳到的最远的地方是nums[i]+i
而决定这个元素能否被遍历到是由之前元素的nums[i]+i是否覆盖此元素来决定的
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int largest = 0;
        for (int i = 0; i <= largest; i++)
        {
            if (largest >= nums.size() - 1)
                return true;
            largest = max(largest, nums[i] + i);
        }
        return false;
    }
};

int main()
{
    vector<int> nums{4, 2, 0, 0, 1, 1, 4, 4, 4, 0, 4, 0};
    Solution s;
    cout << s.canJump(nums);
}