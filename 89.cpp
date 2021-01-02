/*
找规律+动态规划
x<<y = 把x二进制化，在x右边加上y个0
x>>y = 把x二进制化，在x右边减去y个0
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result(1);
        result[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int e = 1 << (i - 1); //i - 1位结果前增加一位1
            for (int j = result.size() - 1; j >= 0; j--)
            { // 镜像排列
                result.push_back(e + result[j]);
            }
        }
        return result;
    }
}

// class Solution
// {
// public:
//     vector<int> grayCode(int n)
//     {
//         int code_num = pow(2, n);
//         vector<int> list;
//         list.push_back(0);
//         if (n = 0)
//         {
//             return list;
//         }
//         for (int i = 1; i < code_num; i++)
//         {
//             int j = i >> 1;
//             list.push_back(i ^ j);
//         }
//         return list;
//     }
// };

int
main()
{
    Solution s;
    vector<int> ans = s.grayCode(5);
}