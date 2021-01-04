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
public:
    int numTrees(int n)
    {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        // i只代表长度，我们也只关心长度
        for (int i = 2; i <= n; ++i)
        {
            // j代表在长度为i的串中，依次挑选长度做根
            for (int j = 1; j <= i; ++j)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

//能做，但是递归太慢了
// class Solution
// {
// private:
//     int dfs(int start, int end)
//     {
//         int num = 0;
//         if (start > end)
//             return 1;

//         for (int i = start; i <= end; i++)
//         {
//             int left = dfs(start, i - 1);
//             int right = dfs(i + 1, end);
//             num += left * right;
//         }
//         return num;
//     }

// public:
//     int numTrees(int n)
//     {
//         return dfs(1, n);
//     }
// };

int main()
{
    Solution s;
    int ans = s.numTrees(19);
    cout << ans;
}