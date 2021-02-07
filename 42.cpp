/*
类似与11题
两个指针从左端右端开始搜索，就规避了右端失效末尾情况的考虑
维持两个变量保持左右遍历到的最大的数
左右端中数字小的那一个往中间靠
如果当前数字大于最大数，更新最大值；如小于，增加水池容量
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }

    // int trap(vector<int> &height)
    // {
    //     vector<int>::iterator pt1 = height.begin(), pt2 = height.begin() + 1;
    //     int sum = 0, loc = 0;
    //     while (pt2 != height.end())
    //     {
    //         if (*pt2 < *pt1)
    //         {
    //             if (pt2 == height.end() - 1)
    //             {
    //                 reverse(pt1, height.end());
    //                 pt2 = pt1 + 1;
    //                 loc = 0;
    //             }
    //             else
    //             {
    //                 loc += (*pt1 - *pt2);
    //                 pt2++;
    //             }
    //         }
    //         else
    //         {
    //             sum += loc;
    //             loc = 0;
    //             pt1 = pt2;
    //             pt2++;
    //         }
    //     }
    //     return sum;
    // }
};

int main()
{
    Solution s;
    vector<int> height{5, 4, 1, 2};
    cout << s.trap(height);
}