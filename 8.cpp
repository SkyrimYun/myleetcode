/*
不止在乘除10的时候可能会溢出
加减的时候一样可能会溢出
还是🉐用long
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long ret = 0;
        if (s.empty())
            return ret;

        int first = 0;
        while (s[first] == ' ')
            first++;

        bool reverse = false;
        if (!isdigit(s[first]) && s[first] != '+' && s[first] != '-')
            return ret;
        else if (s[first] == '+')
            first++;
        else if (s[first] == '-')
        {
            first++;
            reverse = true;
        }

        while (isdigit(s[first]))
        {
            if (ret > INT32_MAX / 10)
            {
                ret = INT32_MAX;
                break;
            }
            if (ret < INT32_MIN / 10)
            {
                ret = INT32_MIN;
                break;
            }
            ret *= 10;
            ret = reverse ? ret - (s[first] - '0') : ret + (s[first] - '0');
            first++;
        }

        if (ret > INT32_MAX)
            return INT32_MAX;
        if (ret < INT32_MIN)
            return INT32_MIN;
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("2147483648");
}