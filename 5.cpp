/*
动态规划 Dynamic Programming

【无后效性】　“未来与过去无关”，这就是无后效性。（严格定义：如果给定某一阶段的状态，则在这一阶段以后过程的发展不受这阶段以前各段状态的影响。）
【最优子结构】　大问题的最优解可以由小问题的最优解推出，这个性质叫做“最优子结构性质”。　　

一个问题能否用DP解决？ 
    --能将大问题拆成几个小问题，且满足无后效性、最优子结构性质。

暴力做法是枚举所有的可能解，这是最大的可能解空间。
    DP是枚举有希望成为答案的解。这个空间比暴力的小得多。
    也就是说：DP自带剪枝。
一言以蔽之：大事化小，小事化了。
    将一个大问题转化成几个小问题；
    求解小问题；
    推出大问题的解。

通用的设计DP算法的步骤。　　
首先，把我们面对的局面表示为x。这一步称为设计状态。　　
对于状态x，记我们要求出的答案(e.g. 最小费用)为f(x).
找出f(x)与哪些局面有关（记为p），写出一个式子（称为状态转移方程），通过f(p)来推出f(x).
【DP三连】　　
    设计DP算法，往往可以遵循DP三连：　　
    我是谁？  ——设计状态，表示局面　　
    我从哪里来？　　
    我要到哪里去？  ——设计转移


*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
对于一个子串而言，如果它是回文串，并且长度大于2，那么将它首尾的两个字母去除之后，它仍然是个回文串。例如对于字符串“ababa”，如果我们已经知道“bab” 是回文串，那么“ababa” 一定是回文串，这是因为它的首尾两个字母都是“a”。
根据这样的思路，我们就可以用动态规划的方法解决本题。我们用 P(i,j)P(i,j) 表示字符串 s 的第 i 到 j 个字母组成的串（下文表示成 s[i:j]s[i:j]）
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ret;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int length = 1; length <= s.size(); length++)
        {
            for (int start = 0; start + length <= s.size(); start++)
            {
                int end = start + length - 1;

                if (length == 1) //length为1的情况
                    dp[start][end] = true;
                else if (length == 2) //length为2的情况
                    dp[start][end] = s[start] == s[end];
                else
                    dp[start][end] = s[start] == s[end] && dp[start + 1][end - 1]; //状态转移方程

                if (dp[start][end] && ret.size() < length)
                    ret = s.substr(start, length);
            }
        }
        return ret;
    }
};