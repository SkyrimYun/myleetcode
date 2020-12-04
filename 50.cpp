/*
实现快速幂运算
要用到二分法
x→x2→x4→x9→x19→x38→x77
求解x的77次方的时候
相较于把x乘77次
可以把中间结果直接平方来加快运行速度
这样只需要6次就完成了计算
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
    double binser(double x, long n)
    {
        if (n == 0 || x == 1)
            return 1;

        double y = binser(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x; //注意这里的条件
    }

public:
    double myPow(double x, int n)
    {
        long N = n;
        return N >= 0 ? binser(x, N) : 1 / binser(x, -N);
    }
};

//迭代法
// class Solution
// {
// public:
//     double quickMul(double x, long long N)
//     {
//         double ans = 1.0;
//         // 贡献的初始值为 x
//         double x_contribute = x;
//         // 在对 N 进行二进制拆分的同时计算答案
//         while (N > 0)
//         {
//             if (N % 2 == 1)
//             {
//                 // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
//                 ans *= x_contribute;
//             }
//             // 将贡献不断地平方
//             x_contribute *= x_contribute;
//             // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
//             N /= 2;
//         }
//         return ans;
//     }

//     double myPow(double x, int n)
//     {
//         long long N = n;
//         return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
//     }
// };
