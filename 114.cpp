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
    vector<TreeNode *> preorder;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        preorder.emplace_back(root);
        dfs(root->left);
        dfs(root->right);
    }

public:
    void flatten(TreeNode *root)
    {
        if (root)
        {
            dfs(root);
            for (int i = 0; i < preorder.size() - 1; i++)
            {
                preorder[i]->left = nullptr;
                preorder[i]->right = preorder[i + 1];
            }
            preorder.back()->left = nullptr;
            preorder.back()->right = nullptr;
        }
    }

    //迭代
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *prev = nullptr;
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (prev)
            {
                prev->left = nullptr;
                prev->right = cur;
            }
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
            prev = cur;
        }
    }

    // in place
    // 寻找前驱节点
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *left = cur->left;
                TreeNode *preseccor = cur->left;
                while (preseccor->right)
                    preseccor = preseccor->right;
                preseccor->right = cur->right;
                cur->left = nullptr;
                cur->right = left;
            }
            cur = cur->right;
        }
    }
};