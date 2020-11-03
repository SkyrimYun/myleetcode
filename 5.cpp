/*
对于一个子串而言，如果它是回文串，并且长度大于2，那么将它首尾的两个字母去除之后，它仍然是个回文串。例如对于字符串“ababa”，如果我们已经知道“bab” 是回文串，那么“ababa” 一定是回文串，这是因为它的首尾两个字母都是“a”。
根据这样的思路，我们就可以用动态规划的方法解决本题。我们用 P(i,j)P(i,j) 表示字符串 s 的第 i 到 j 个字母组成的串（下文表示成 s[i:j]s[i:j]）
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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

                if (length == 1)
                    dp[start][end] = true;
                else if (length == 2)
                    dp[start][end] = s[start] == s[end];
                else
                    dp[start][end] = s[start] == s[end] && dp[start + 1][end - 1];

                if (dp[start][end] && ret.size() < length)
                    ret = s.substr(start, length);
            }
        }
        return ret;
    }
};