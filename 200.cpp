/*
在递归中使用全局visited变量之前，多想一想这个是否必须
这道题里面就可以使用修改原数组的方式规避掉使用全局visited
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

class Solution
{
private:
    int islands;
    int m;
    int n;
    bool dfs(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j);
        if (i < m - 1 && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1);
        if (j < n - 1 && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1);

        return true;
    }

public:
    int
    numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};

int main()
{
    vector<vector<char>> grid{{'1', '1'}};
    Solution s;
    cout << s.numIslands(grid);
}