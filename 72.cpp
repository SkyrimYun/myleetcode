/*
dp[i][j]代表从word1的前i个字母变化到word2的前j个字母需要多少步骤

考虑 增删改 这三个步骤
同时考虑word1和word2，其实一共只有三个步骤
1。增加word1，等同于删减word2
2。增加word2，等同于删减word1
3。修改word1，等同于反向修改word2

转移方程：
dp[i][j]可由三种可能构成
1.dp[i][j-1]+1；相当于进行增加word2末尾操作
2.dp[i-1][j]+1; 相当于进行增加word1末尾操作
3.dp[i-1][j-1]+1；相当于进行修改word1末尾操作
所以 dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1
注意如果word1[i]==word2[j]，就不需要最后加1了
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        if (m * n == 0)
            return m + n;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m + 1; i++)
            dp[i][0] = i;

        for (int i = 0; i < n + 1; i++)
            dp[0][i] = i;

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                int left = dp[i - 1][j];
                int down = dp[i][j - 1];
                int left_down = dp[i - 1][j - 1];
                if (word1[i - 1] == word2[j - 1])
                    left_down--;
                dp[i][j] = min(left, min(down, left_down)) + 1;
            }
        }
        return dp[m][n];
    }
};