/*
stack的pop()只吐出，不返回
用stack.top()访问最上层元素
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
private:
    unordered_map<char, int> bracket;

public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        bracket.emplace('(', 1);
        bracket.emplace('{', 2);
        bracket.emplace('[', 3);
        bracket.emplace(')', 4);
        bracket.emplace('}', 5);
        bracket.emplace(']', 6);
        stack<char> pair;
        for (char c : s)
        {
            if (bracket[c] <= 3)
                pair.push(c);
            else if (bracket[c] > 3 && !pair.empty() && bracket[c] == bracket[pair.top()] + 3)
                pair.pop();
            else
                return false;
        }
        return pair.empty();
    }
};