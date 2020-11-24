/*
对于递归题
如果是求单一解，最好设置一个布尔量，以便递归在找到解之后立刻结束
如果是求解的合集，则需要搜索全部可能情况
利用vector<bool> used来更新搜索空间是一个常见做法
*/

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
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sz = nums.size();
        input = nums;
        used = vector<bool>(sz, false);
        dfs(vector<int>());
        return ret;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution s;
    vector<vector<int>> ret = s.permute(nums);
    for (vector<int> perm : ret)
    {
        for (int x : perm)
        {
            cout << x << ",";
        }
        cout << endl;
    }
}