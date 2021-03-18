/*
前序遍历结构：
    根节点+左子树+右子树
中序遍历结构：
    左子树+根节点+右子树

前序遍历的第一个元素必为根节点，找到根节点在中序遍历中的位置后便可以确定左子树和右子树大小
然后开始递归

此题的迭代解法用到了更具体的前序中旬遍历结构
前序遍历从结构上来看，先一路遍历左儿子，拉到树的左下角，再从左下角往回，从下往上遍历右儿子。相当于把一棵树以左右儿子来分层，然后Z字型遍历各层
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
    unordered_map<int, int> hash_table;
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
            return nullptr;

        TreeNode *sub_root = new TreeNode(preorder[preorder_left]);
        int index = hash_table[preorder[preorder_left]];
        int left_sz = index - inorder_left;
        int right_sz = inorder_right - index;
        sub_root->left = dfs(preorder, inorder, preorder_left + 1, preorder_left + left_sz, inorder_left, index - 1);
        sub_root->right = dfs(preorder, inorder, preorder_left + left_sz + 1, preorder_right, index + 1, inorder_right);
        return sub_root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int size = inorder.size();

        for (int i = 0; i < size; i++)
        {
            hash_table[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, size - 1, 0, size - 1);
    }

    // 迭代
    /*
    我们用一个栈和一个指针辅助进行二叉树的构造。初始时栈中存放了根节点（前序遍历的第一个节点），指针指向中序遍历的第一个节点；

    我们依次枚举前序遍历中除了第一个节点以外的每个节点。如果 index 恰好指向栈顶节点，那么我们不断地弹出栈顶节点并向右移动 index，并将当前节点作为最后一个弹出的节点的右儿子；如果 index 和栈顶节点不同，我们将当前节点作为栈顶节点的左儿子；

    无论是哪一种情况，我们最后都将当前的节点入栈。
    */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (!preorder.size())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i)
        {
            int preorderVal = preorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};