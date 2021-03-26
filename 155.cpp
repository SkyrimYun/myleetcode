/*
这个题考的不是怎么实现栈，而是怎么实现一个最小栈
维持两个栈，一个储存数据，一个储存栈压倒这里时的最小值即可
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
#include <list>

using namespace std;

class MinStack
{
private:
    stack<int> nums;
    stack<int> mins;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int val)
    {
        nums.push(val);
        if (mins.empty())
            mins.push(val);
        else
            mins.push(min(mins.top(), val));
    }

    void pop()
    {
        nums.pop();
        mins.pop();
    }

    int top()
    {
        return nums.top();
    }

    int getMin()
    {
        return mins.top();
    }
};