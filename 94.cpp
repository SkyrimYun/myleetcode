/*
如果把左节点和右节点的位置固定不动，那么根节点放在左节点的左边，称为前序（pre-order）
根节点放在左节点和右节点的中间，称为中序（in-order）
根节点放在右节点的右边，称为后序（post-order）
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

//Definition for a binary tree node.
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
    vector<int> ret;
    void dfs(TreeNode *root)
    {
        if (root->left != nullptr)
            dfs(root->left);
        ret.emplace_back(root->val);
        if (root->right != nullptr)
            dfs(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
            dfs(root);
        return ret;
    }
};