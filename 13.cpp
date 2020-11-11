/*
罗马数字转阿拉伯数字
    对于特殊情况，利用roman[s[i]]会小于roman[s[i+1]]的特殊性质，特殊处理即可，不用分类讨论
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman{{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (roman[s[i]] < roman[s[i + 1]])
                ret -= roman[s[i]];
            else
                ret += roman[s[i]];
        }
        return ret;
    }
};