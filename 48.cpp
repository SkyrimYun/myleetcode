#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int sz = matrix.size();

        //transpose
        for (int i = 0; i < sz; i++)
        {
            for (int j = i; j < sz; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        //flip
        for (int i = 0; i < sz; i++)
        {
            for (int j = i; j < sz / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][sz - 1 - j];
                matrix[i][sz - 1 - j] = temp;
            }
        }
    }
};