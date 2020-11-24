#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> blks(9);

        char c = ' ';
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                c = board[i][j];
                if (c == '.')
                    continue;

                if (rows[i].count(c) > 0 || cols[j].count(c) > 0 || blks[(i / 3) * 3 + j / 3].count(c) > 0)
                    return false;
                else
                {
                    rows[i].emplace(c);
                    cols[j].emplace(c);
                    blks[(i / 3) * 3 + j / 3].emplace(c);
                }
            }
        }
        return true;
    }
};
