#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i < dp.size(); i++)
        {
            int n1 = s[i - 1] == '0' ? 0 : dp[i - 1];
            int double_num = s[i - 2] == '0' ? 0 : ((s[i - 2] - '0') * 10 + s[i - 1] - '0');
            int n2 = double_num <= 26 && double_num > 0 ? dp[i - 2] : 0;
            if (n1 == 0 && n2 == 0)
                break;
            dp[i] = n1 + n2;
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    s.numDecodings("2214");
}