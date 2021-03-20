#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

class Solution
{
private:
    unordered_set<string> dict;
    bool dfs(string s)
    {
        for (int i = 1; i <= s.size(); i++)
        {
            if (dict.count(s.substr(0, i)) > 0)
            {
                if (i == s.size() || dfs(s.substr(i, s.size() - i)))
                    return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string &ss : wordDict)
            dict.insert(ss);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && dict.count(s.substr(j, i - j)) > 0)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
    //递归复杂度得不到保证
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     for (string &ss : wordDict)
    //         dict.insert(ss);
    //     return dfs(s);
    // }
};