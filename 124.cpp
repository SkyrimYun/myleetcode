/*
树中的路径必然有一个顶点，而经过这个顶点的所有路径中最大的路径，必然是左子树中以左儿子为终点的最大路径加上右子树中以右儿子为起点的最大路径，之和
就可以递归了
dfs计算的是以当前节点为终点或起点的路径的最大值，这个值就是 node->val + max(left_max,right_max)
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
    int maxGain = INT32_MIN;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_sum = max(dfs(root->left), 0);
        int right_sum = max(dfs(root->right), 0);
        int sum = root->val + left_sum + right_sum;
        maxGain = max(maxGain, sum);
        return root->val + max(left_sum, right_sum);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maxGain;
    }
};