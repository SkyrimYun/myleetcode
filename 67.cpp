/*
c++针对stl容器的reverse()函数在 <algorithm> 头文件里
针对两个字符串的操作，如果其长度不同会导致处理困难，可“补足”短的字符串（如填入0）来使其长度相等

c++中的二进制数操作
https://www.cnblogs.com/thujason/archive/2010/07/08/1773529.html
x>>1 往右移一位 010 -> 01
x<<1 往左移一位 010 -> 0100
011 & 101 = 001
011 ^ 101 = 110
011 | 101 = 111
~011 = 100
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
    string addBinary(string a, string b)
    {
        string ret;
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        while (i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            ret.push_back((c & 1) + '0');
            c >>= 1;
        }
        reverse(ret.begin(), ret.end());
        return ret;
        // int sza = a.size();
        // int szb = b.size();
        // int dif = abs(sza - szb);
        // string &shorts = sza >= szb ? b : a;
        // string &longs = sza >= szb ? a : b;
        // string ret;
        // int plusone = 0;
        // int sum = 0;
        // for (int i = min(sza, szb) - 1; i >= 0; i--)
        // {
        //     sum = shorts[i] - '0' + longs[i + dif] - '0' + plusone;
        //     plusone = sum / 2;
        //     sum %= 2;
        //     ret.insert(ret.begin(), sum + '0');
        // }
        // for (int i = dif - 1; i >= 0; i--)
        // {
        //     sum = longs[i] - '0' + plusone;
        //     plusone = sum / 2;
        //     sum %= 2;
        //     ret.insert(ret.begin(), sum + '0');
        // }
        // if (plusone != 0)
        //     ret.insert(ret.begin(), '1');
        // return ret;
    }
};

int main()
{
    string a = "1010";
    string b = "1011";
    Solution s;
    cout << s.addBinary(a, b);
}