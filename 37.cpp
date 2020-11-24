/*
注意终止条件
在得到解之后应该停止搜索，直接逐层返回
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> blks;
    vector<pair<int, int>> spcs;
    bool valid;

    void dfs(int pos, vector<vector<char>> &board)
    {
        if (pos == spcs.size())
        {
            valid = true;
            return;
        }

        int row = spcs[pos].first;
        int col = spcs[pos].second;
        for (int i = 1; i < 10 && !valid; i++)
        {
            if (rows[row][i] || cols[col][i] || blks[(row / 3) * 3 + col / 3][i])
                continue;
            else
            {
                rows[row][i] = true;
                cols[col][i] = true;
                blks[(row / 3) * 3 + col / 3][i] = true;
                board[row][col] = i + '0';
                dfs(pos + 1, board);
                rows[row][i] = false;
                cols[col][i] = false;
                blks[(row / 3) * 3 + col / 3][i] = false;
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        rows = vector<vector<bool>>(9, vector<bool>(10, false));
        cols = vector<vector<bool>>(9, vector<bool>(10, false));
        blks = vector<vector<bool>>(9, vector<bool>(10, false));

        char c = ' ';
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                c = board[i][j];
                if (c == '.')
                {
                    spcs.emplace_back(i, j);
                    continue;
                }

                rows[i][c - '0'] = true;
                cols[j][c - '0'] = true;
                blks[(i / 3) * 3 + j / 3][c - '0'] = true;
            }
        }

        valid = false;
        dfs(0, board);
    }
};

int main()
{
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    s.solveSudoku(board);
}