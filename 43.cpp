/*
在不确定字符串长度的时候
不如先初始化一个肯定足够用的
然后最后再来做剪切
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
    string multiply(string num1, string num2)
    {
        // if (num1 == "0" || num2 == "0")
        //     return "0";
        // string ret;
        // int i, j;
        // int nd = 0;
        // for (i = 0; i < num2.size(); i++)
        // {
        //     string itreslut;
        //     for (j = num1.size() - 1; j >= 0; j--)
        //     {
        //         int val = (num1[j] - '0') * (num2[i] - '0');
        //         val += nd;
        //         itreslut.insert(itreslut.begin(), val % 10 + '0');
        //         nd = val / 10;
        //     }
        //     if (nd != 0)
        //     {
        //         itreslut.insert(itreslut.begin(), nd + '0');
        //         nd = 0;
        //     }

        //     if (i == 0)
        //         ret = itreslut;
        //     else
        //     {
        //         ret.push_back(itreslut[itreslut.size() - 1]);
        //         int n;
        //         for (n = ret.size() - 2; n >= ret.size() - itreslut.size() && n >= 0; n--)
        //         {
        //             int val = (ret[n] - '0') + (itreslut[itreslut.size() + n - ret.size()] - '0');
        //             val += nd;
        //             ret[n] = val % 10 + '0';
        //             nd = val / 10;
        //         }
        //         while (nd != 0 && n >= 0)
        //         {
        //             int val = ret[n] - '0' + nd;
        //             ret[n] = val % 10 + '0';
        //             nd = val / 10;
        //             n--;
        //         }
        //         if (nd != 0)
        //         {
        //             ret.insert(ret.begin(), nd + '0');
        //             nd = 0;
        //         }
        //     }

        //     itreslut.clear();
        // }
        // return ret;

        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1 + n2, '0');
        for (int i = n2 - 1; i >= 0; i--)
        {
            for (int j = n1 - 1; j >= 0; j--)
            {
                int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                res[i + j + 1] = temp % 10 + '0'; //当前位
                res[i + j] += temp / 10;          //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }

        //去除首位'0'
        for (int i = 0; i < n1 + n2; i++)
        {
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";
    }
};

int main()
{
    string num1 = "237";
    string num2 = "284";
    Solution s;
    cout << s.multiply(num1, num2);
}