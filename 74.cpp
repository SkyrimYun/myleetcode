/*
二分法如果用于搜索目标值在哪一个区间内
start返回的是刚好大于目标值的index (可能会越上界)
end返回的是刚好小于目标值的index （可能会越下界）
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
    int binarysearch(vector<int> &nums, int target)
    {
        int sz = nums.size();
        int first = 0;
        int last = sz - 1;
        int mid = sz / 2;

        while (first <= last)
        {
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                first = mid + 1;
            else
                last = mid - 1;

            mid = (first + last) / 2;
        }
        return last;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> firstcol;
        const int m = matrix.size();
        const int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            firstcol.emplace_back(matrix[i][0]);
        }
        int row = binarysearch(firstcol, target);

        if (row < 0)
            return false;
        int col = binarysearch(matrix[row], target);
        if (matrix[row][col] != target)
            return false;
        else
            return true;
    }
};

int main()
{
    Solution s;
    s.searchMatrix();
}