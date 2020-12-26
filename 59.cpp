#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int rows = n;
        int cols = n;

        vector<vector<int>> ret(n, vector<int>(n));
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        int row = 0, col = 0, i = 1;
        int direction = 0;
        while (i <= cols * rows)
        {
            if (row < rows && col < cols && row >= 0 && col >= 0 && !used[row][col])
            {
                ret[row][col] = i;
                used[row][col] = true;
                i++;
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
    Solution s;
    vector<vector<int>> ret = s.generateMatrix(3);
    for (vector<int> row : ret)
    {
        for (int val : row)
        {
            cout << val << ",";
        }
        cout << endl;
    }
}