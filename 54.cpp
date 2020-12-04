#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> ret;
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        int row = 0, col = 0;
        int direction = 0;
        while (ret.size() < cols * rows)
        {
            if (row < rows && col < cols && row >= 0 && col >= 0 && !used[row][col])
            {
                ret.emplace_back(matrix[row][col]);
                used[row][col] = true;
            }
            else
            {
                if (direction == 0)
                    col--;
                else if (direction == 1)
                    row--;
                else if (direction == 2)
                    col++;
                else if (direction == 3)
                    row++;
                direction = direction == 3 ? 0 : direction + 1;
            }

            if (direction == 0)
                col++;
            else if (direction == 1)
                row++;
            else if (direction == 2)
                col--;
            else if (direction == 3)
                row--;
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    vector<int> ret = s.spiralOrder(matrix);
    for (int x : ret)
    {
        cout << x << ",";
    }
}