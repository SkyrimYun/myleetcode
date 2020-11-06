/*
水桶问题
双指针法并不是说是最优搜索，只是减小了搜索空间
搜索方向朝着“最有可能得到更好的解”前进
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0, end = height.size() - 1;
        int ret = 0;
        while (start < end)
        {
            int area = (end - start) * min(height[start], height[end]);
            ret = max(ret, area);
            if (height[start] > height[end])
                end--;
            else
                start++;
        }
        return ret;
    }
};