#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<int>> ret;
    int sz;
    vector<int> input;
    vector<bool> used;
    void dfs(vector<int> perm)
    {
        if (perm.size() == sz)
        {
            ret.emplace_back(perm);
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            if (used[i])
                continue;
            perm.emplace_back(input[i]);
            used[i] = true;
            dfs(perm);
            perm.erase(perm.end() - 1);
            used[i] = false;
            while (i < sz - 1 && input[i + 1] == input[i])
                i++;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sz = nums.size();
        sort(nums.begin(), nums.end());
        input = nums;
        used = vector<bool>(sz, false);
        dfs(vector<int>());
        return ret;
    }
};