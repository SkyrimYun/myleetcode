/*
剔除vector最后一个元素用pop_back()最好，erase(end()-1)太慢了
写递归的时候注意剪枝；缩小搜索空间能加快速度
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
    vector<vector<int>> ans;
    int sz;
    int max;
    void dfs(vector<int> &candidate, int pos)
    {
        if (candidate.size() == sz)
        {
            ans.emplace_back(candidate);
            return;
        }

        for (int i = pos; i <= max - (sz - candidate.size()) + 1; i++)
        {
            candidate.emplace_back(i);
            dfs(candidate, i + 1);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        sz = k;
        max = n;
        vector<int> candidate;
        dfs(candidate, 1);
        return ans;
    }
};