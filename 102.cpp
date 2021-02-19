/*
和二叉树有关的迭代法中常用到quene结构
先进，先出
把每一层的node都压入quene，再依次吐出，然后压入其子节点
其实迭代法的本质也就算广度优先搜索BFS
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    vector<vector<int>> levels;
    void dfs(TreeNode *cur, int level)
    {
        if (cur)
        {
            if (level == levels.size())
                levels.push_back(vector<int>{cur->val});
            else
                levels[level].push_back(cur->val);
        }
        else
            return;
        dfs(cur->left, level + 1);
        dfs(cur->right, level + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        dfs(root, 0);
        return levels;
    }

    //迭代法
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     queue<TreeNode *> que;
    //     que.push(root);
    //     vector<vector<int>> res;
    //     while (que.size() != 0)
    //     {
    //         int size = que.size();
    //         vector<int> level;
    //         while (size--)
    //         {
    //             TreeNode *cur = que.front();
    //             que.pop();
    //             if (!cur)
    //             {
    //                 continue;
    //             }
    //             level.push_back(cur->val);
    //             que.push(cur->left);
    //             que.push(cur->right);
    //         }
    //         if (level.size() != 0)
    //         {
    //             res.push_back(level);
    //         }
    //     }
    //     return res;
    // }
};