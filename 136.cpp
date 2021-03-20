/*
任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a
任何数和其自身做异或运算，结果是 0，即 a⊕a=0
异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b
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
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (auto e : nums)
            ret ^= e;
        return ret;
    }

    // int singleNumber(vector<int> &nums)
    // {
    //     if (nums.size() == 1)
    //         return nums[0];

    //     int pt1 = 0, pt2 = 1;
    //     while (pt2 < nums.size())
    //     {
    //         if (nums[pt1] == nums[pt2])
    //         {
    //             nums[pt2] = INT32_MAX;
    //             nums[pt1] = INT32_MAX;
    //             pt2++;
    //             while (nums[pt1] == INT32_MAX)
    //                 pt1++;
    //             if (pt1 == pt2)
    //                 pt2++;
    //         }
    //         else
    //             pt2++;
    //     }
    //     return nums[pt1];
    // }
};