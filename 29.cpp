/*
保持递归函数的整洁
可以的话就用Long来处理整数溢出问题
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
private:
    long dg(long a, long b)
    {
        if (a < b)
            return 0;

        long divisor = b;
        long ret = 1;
        while (a >= divisor)
        {
            ret *= 2;
            divisor *= 2;
        }

        return ret / 2 + dg(a - divisor / 2, b);
    }

public:
    int divide(int dividend, int divisor)
    {
        bool reverse = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            reverse = true;

        long a = abs(dividend), b = abs(divisor);
        long ret = reverse ? -dg(a, b) : dg(a, b);
        if (ret > INT32_MAX)
            ret = INT32_MAX;
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.divide(16, -4);
}