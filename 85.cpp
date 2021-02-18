/*
回归本源：一个矩形 = 长 + 宽
在每一个位置储存单行横向的连续1的个数，这是宽
想象把矩阵横过来，每一个位置都储存了一个高度，
对原本的每一列来说，这就是一个84题，求柱状图最大矩形面积的问题
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[i][j] = j == 0 ? 0 : (left[i][j - 1] + 1);
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++)
        {
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                down[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++)
            {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }

    // 更简介的动态规划法，但性能更低
    // 使用了两个dp变量
    // 一个表示纵向的累计高度 height
    // 一个表示以此位置作为右下角能造成的面积 dp； k表示宽度
    // 思考： 一个dp结构无法很好的表示问题的时候，考虑一下用两个
    /*
    heights[i][j]代表[i，j]的高度
    heights[i][j] = matrix[i][j]=='1'? heights[i-1][j] + 1:0

    dp[i][j][k] 代表以[i,j]为右下角，高度为k可以组成的面积
    dp[i][j][k] = dp[i][j-1][k] + k  
    */
    // int maximalRectangle(vector<vector<char>> &matrix)
    // {
    //     int n = matrix.size();
    //     int m = 0;
    //     if (n > 0)
    //     {
    //         m = matrix[0].size();
    //     }
    //     vector<vector<int>> heights(n + 1, vector<int>(m + 1, 0));
    //     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    //     int ans = 0;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= m; j++)
    //         {
    //             if (matrix[i - 1][j - 1] == '0')
    //             {
    //                 continue;
    //             }
    //             heights[i][j] = heights[i - 1][j] + 1;
    //             for (int k = 1; k <= heights[i][j]; k++)
    //             {
    //                 dp[i][j][k] = dp[i][j - 1][k] + k;
    //                 ans = max(ans, dp[i][j][k]);
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

int main()
{
    vector<vector<char>> maxtrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution s;
    cout << s.maximalRectangle(maxtrix);
}