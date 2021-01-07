#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    // vector<int> spiralOrder(vector<vector<int>> &matrix)
    // {
    //     int rows = matrix.size();
    //     int cols = matrix[0].size();

    //     vector<int> ret;
    //     vector<vector<bool>> used(rows, vector<bool>(cols, false));
    //     int row = 0, col = 0;
    //     int direction = 0;
    //     while (ret.size() < cols * rows)
    //     {
    //         if (row < rows && col < cols && row >= 0 && col >= 0 && !used[row][col])
    //         {
    //             ret.emplace_back(matrix[row][col]);
    //             used[row][col] = true;
    //         }
    //         else
    //         {
    //             if (direction == 0)
    //                 col--;
    //             else if (direction == 1)
    //                 row--;
    //             else if (direction == 2)
    //                 col++;
    //             else if (direction == 3)
    //                 row++;
    //             direction = direction == 3 ? 0 : direction + 1;
    //         }

    //         if (direction == 0)
    //             col++;
    //         else if (direction == 1)
    //             row++;
    //         else if (direction == 2)
    //             col--;
    //         else if (direction == 3)
    //             row--;
    //     }
    //     return ret;
    // }

    // 一种更经凑的方法，不用记忆某一格是否被使用，而是重新定义上下左右边界
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        if (matrix.empty())
            return ret;
        int upper = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (true)
        {
            // left to right
            for (int i = left; i <= right; i++)
                ret.emplace_back(matrix[upper][i]);
            if (++upper > bottom)
                break;
            //up to down
            for (int i = upper; i <= bottom; i++)
                ret.emplace_back(matrix[i][right]);
            if (--right < left)
                break;
            //right to left
            for (int i = right; i >= left; i--)
                ret.emplace_back(matrix[bottom][i]);
            if (--bottom < upper)
                break;
            //down to up
            for (int i = bottom; i >= upper; i--)
                ret.emplace_back(matrix[i][left]);
            if (++left > right)
                break;
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