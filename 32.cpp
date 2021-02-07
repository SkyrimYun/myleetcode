#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size(), 0);
        int maxlength = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else
                {
                    if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxlength = max(maxlength, dp[i]);
            }
        }
        return maxlength;
    }
};