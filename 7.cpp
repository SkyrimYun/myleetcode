/*
如果整数溢出问题太麻烦
直接上long
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long ret = 0;
        while (x != 0)
        {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        if (ret > INT32_MAX || ret < INT32_MIN)
            return 0;
        else
            return ret;
    }
};