/*
很有趣的一题
因为是要判断是否对陈，左子树需要是右子树的镜像翻转
在递归中参数带上两个指针，以这两个指针为根的树如果是镜像翻转需要满足：t1的左子树需要是t2的右子树的镜像翻转；t1的右子树需要是t2的左子树的镜像翻转，且t1和t2值相等
有点玄妙

迭代法则是需要使用一个quene，只要quene不空，每轮吐两个指针出来比较，并且依次把 n1的左、n2的右、n1的右、n2的左压入quene
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

//Definition for a binary tree node.
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
    bool dfs(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2)
            return false;

        return t1->val == t2->val && dfs(t1->right, t2->left) && dfs(t1->left, t2->right);
    }

    bool diedai(TreeNode *t1, TreeNode *t2)
    {
        queue<TreeNode *> q;
        q.push(t1);
        q.push(t2);
        while (!q.empty())
        {
            TreeNode *n1 = q.front();
            q.pop();
            TreeNode *n2 = q.front();
            q.pop();
            if (!n1 && !n2)
                continue;
            if (!n1 || !n2 || n1->val != n2->val)
                return false;
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);
        }
        return true;
    }

public:
    // bool isSymmetric(TreeNode *root)
    // {
    //     return dfs(root, root);
    // }

    bool isSymmetric(TreeNode *root)
    {
        return diedai(root, root);
    }
};