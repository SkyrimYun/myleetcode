/*
用动态规划解决正则表达式
贼难理解

dp[i][j]表示 s的前i个字符与p的前j个字符能否匹配
注意这里的i和j不是index，是个数，所以dp大小(m+1)*(n+1)，dp的index到s和p的index要减1

核心转换方程
1.如果p[j-1]为一般字母
    dp[i][j]=dp[i-1][j-1] if s[i-1]==p[j-1]
    dp[i][j]=false        if s[i-1]!=p[j-1]
2.如果p[j-1] == '*'
    dp[i][j]=dp[i-1][j]||dp[i][j-2]   if s[i-1]==p[j-2]
    dp[i][j]=dp[i][j-2]               if s[i-1]!=p[j-2]
    判断条件：s中的当前字母是否与p中*号前一个字母相等
    如不相等，由于*号也能代表0个，所以只要dp[i][j-2]为真，dp[i][j]就也能为真
    如相等，除了0个意外，p中字母+*号组合能被重复任意多次，所以只要上一个dp[i-1][j]为真，dp[i][j]就也能为真
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

class Solution
{
private:
    bool match(char a, char b)
    {
        if (b == '.')
            return true;
        return a == b;
    };

public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    if (i != 0 && match(s[i - 1], p[j - 2]))
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    }
                    else
                        dp[i][j] = dp[i][j - 2];
                }
                else
                {
                    if (i != 0 && match(s[i - 1], p[j - 1]))
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    s.isMatch("aa", "a*");
}