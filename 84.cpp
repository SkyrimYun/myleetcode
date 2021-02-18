/*
要点在于，以某一根柱子为中心，面积能否扩展到左右？左右的柱子比中心高 -> 可行； 比中心低 -> 不行
怎样快速判断左右能扩展到的最远距离？
压栈
比如向右边遍历（寻找每一个柱子能扩展到左边的最远距离），碰到遍历到的柱子比栈顶高，此柱子向左最远就能到栈顶，比栈顶底，吐出栈顶并把新栈顶当作此柱子向左最远能到的地方
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);

        //
        stack<int> mono_stack;
        for (int i = 0; i < n; i++)
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            left[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            right[i] = mono_stack.empty() ? n : mono_stack.top();
            mono_stack.push(i);
        }

        //一次遍历
        // stack<int> mono_stack;
        // for (int i = 0; i < n; ++i)
        // {
        //     while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
        //     {
        //         right[mono_stack.top()] = i;
        //         mono_stack.pop();
        //     }
        //     left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
        //     mono_stack.push(i);
        // }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        return ans;
    }
};

int main()
{
    vector<int> heights{5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    Solution s;
    s.largestRectangleArea(heights);
}