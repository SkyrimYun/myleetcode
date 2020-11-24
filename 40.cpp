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
    vector<int> input;
    void dfs(vector<int> &sol, int target, int pos)
    {
        for (int i = pos; i < input.size(); i++)
        {
            if (input[i] == target)
            {
                sol.emplace_back(input[i]);
                ret.emplace_back(sol);
                sol.erase(sol.end() - 1);
                return;
            }

            if (input[i] > target)
                return;

            sol.emplace_back(input[i]);
            target -= input[i];
            dfs(sol, target, i + 1);
            sol.erase(sol.end() - 1);
            target += input[i];

            while (i < input.size() - 1 && input[i] == input[i + 1])
                i++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        input = candidates;
        vector<int> sol;
        dfs(sol, target, 0);
        return ret;
    }
};