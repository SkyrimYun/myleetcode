#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Solution
{
private:
    vector<vector<int>> ret;
    void dfs(vector<int> &temp, vector<int> &nums, int pos)
    {
        if (pos == nums.size())
            return;

        for (int i = pos; i < nums.size(); i++)
        {
            temp.emplace_back(nums[i]);
            ret.emplace_back(temp);
            dfs(temp, nums, i + 1);
            temp.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        ret.emplace_back(temp);
        dfs(temp, nums, 0);
        return ret;
    }
};