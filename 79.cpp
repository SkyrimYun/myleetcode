/*
如果可以的话尽量少用vector<vector<bool>> used这种东西来做全局标记，对性能的影响太大了
把原先board的值设成特殊值以防止重复使用
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
private:
    bool findans;
    int m;
    int n;
    void dfs(int row, int col, int pos, vector<vector<char>> &board, string &word)
    {
        if (pos == word.size())
        {
            findans = true;
            return;
        }

        // up
        if (!findans && row > 0 && board[row - 1][col] == word[pos])
        {
            char temp = board[row - 1][col];
            board[row - 1][col] = 0;
            dfs(row - 1, col, pos + 1, board, word);
            board[row - 1][col] = temp;
        }
        // down
        if (!findans && row < m - 1 && board[row + 1][col] == word[pos])
        {
            char temp = board[row + 1][col];
            board[row + 1][col] = 0;
            dfs(row + 1, col, pos + 1, board, word);
            board[row + 1][col] = temp;
        }
        // left
        if (!findans && col > 0 && board[row][col - 1] == word[pos])
        {
            char temp = board[row][col - 1];
            board[row][col - 1] = 0;
            dfs(row, col - 1, pos + 1, board, word);
            board[row][col - 1] = temp;
        }
        // right
        if (!findans && col < n - 1 && board[row][col + 1] == word[pos])
        {
            char temp = board[row][col + 1];
            board[row][col + 1] = 0;
            dfs(row, col + 1, pos + 1, board, word);
            board[row][col + 1] = temp;
        }
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        findans = false;
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    char temp = board[i][j];
                    board[i][j] = 0;
                    dfs(i, j, 1, board, word);
                    if (findans)
                        return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    cout << s.exist(board, word);
}