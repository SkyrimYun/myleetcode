/*
直接从0到x二分就完事
可以用 (long) mid * mid 来临时改变一个中间结果的变量类型来避免溢出
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
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
        // int start = 0;
        // int end = x;

        // int middle = 0;
        // while (start <= end)
        // {
        //     middle = (start + end) / 2;
        //     if (middle * middle == x)
        //         return middle;
        //     else if (middle * middle > x)
        //         end = middle - 1;
        //     else
        //         start = middle + 1;
        // }

        // return (middle * middle) > x ? middle - 1 : middle;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(20);
}