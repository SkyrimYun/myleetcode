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
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        vector<int> dp(prices.size() - 1, 0);
        dp[0] = prices[1] - prices[0];
        int ret = dp[0];
        for (int i = 1; i < dp.size(); i++)
        {
            if (prices[i + 1] > prices[i])
                dp[i] = prices[i + 1] - prices[i] + (dp[i - 1] >= 0 ? dp[i - 1] : 0);
            else
                dp[i] = dp[i - 1] + prices[i + 1] - prices[i];
            ret = max(dp[i], ret);
        }
        return ret >= 0 ? ret : 0;
    }
};