/*
二叉搜索树BST关键的性质是，假设当前序列长度为 n，如果我们枚举根节点的值为 i，那么根据二叉搜索树的性质我们可以知道左子树的节点值的集合为 [1…i−1]，右子树的节点值的集合为 [i+1…n]
我们定义 generateTrees(start, end) 函数表示当前值的集合为 [start,end]，返回序列 [start,end] 生成的所有可行的二叉搜索树
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<TreeNode *> dfs(int start, int end)
    {
        vector<TreeNode *> ret;
        if (start > end)
            return {nullptr};
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = dfs(start, i - 1);
            vector<TreeNode *> right = dfs(i + 1, end);
            for (auto &l : left)
            {
                for (auto &r : right)
                {
                    TreeNode *cur = new TreeNode(i, l, r);
                    ret.emplace_back(cur);
                }
            }
        }
        return ret;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return dfs(1, n);
    }
};

int main()
{
    Solution s;
    s.generateTrees(3);
}