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
    vector<vector<int>> ans;
    vector<int> input;
    int sz;
    void dfs(vector<int> &candidate, int pos)
    {
        for (int i = pos; i < sz; i++)
        {
            candidate.emplace_back(input[i]);
            ans.emplace_back(candidate);
            dfs(candidate, i + 1);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sz = nums.size();
        input = nums;
        vector<int> candidate;
        ans.emplace_back(candidate);
        dfs(candidate, 0);
        return ans;
    }
};