#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                dp[0] = 1;
            else if (i == 1)
                dp[1] = 2;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};