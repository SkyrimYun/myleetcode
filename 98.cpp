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
    bool dfs(TreeNode *root, long min, long max)
    {
        if (root == nullptr)
            return true;
        if (root->val >= max || root->val <= min)
            return false;

        if (!dfs(root->left, min, root->val) || dfs(root->right, root->val, max))
            return false;
        else
            return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, INT64_MIN, INT64_MAX);
    }
};