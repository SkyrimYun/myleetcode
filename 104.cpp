/*
在二叉树相关问题中使用BFS用到quene结构时
树中每一层元素个数就是当次轮quene的size
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
    int levels = 0;
    void dfs(TreeNode *root, int level)
    {
        if (!root)
            return;
        else
        {
            levels = max(levels, level + 1);
            dfs(root->left, level + 1);
            dfs(root->right, level + 1);
        }
    }

public:
    int maxDepth(TreeNode *root)
    {
        dfs(root, 1);
        return levels;
    }

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int levels = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size > 0)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                size--;
            }
            levels++;
        }
        return levels;
    }
};