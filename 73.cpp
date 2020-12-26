#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

// class Solution
// {
// public:
//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         vector<pair<int, int>> zeros;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == 0)
//                     zeros.emplace_back(make_pair(i, j));
//             }
//         }
//         for (pair<int, int> zero : zeros)
//         {
//             int row = zero.first;
//             int col = zero.second;
//             for (int i = 0; i < m; i++)
//             {
//                 matrix[i][col] = 0;
//             }
//             for (int j = 0; j < n; j++)
//             {
//                 matrix[row][j] = 0;
//             }
//         }
//     }
// };

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool firstrow = false;
        bool firstcol = false;
        const int m = matrix.size();
        const int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        firstrow = true;
                    if (j == 0)
                        firstcol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (firstcol)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (firstrow)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{{1, 0, 3}};
    s.setZeroes(matrix);
}