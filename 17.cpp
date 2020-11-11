#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
private:
    unordered_map<char, string> numMap;
    string input;
    vector<string> ret;
    void dfs(string ans, int pos)
    {
        if (pos == input.size())
        {
            ret.emplace_back(ans);
            return;
        }

        for (char c : numMap[input[pos]])
        {
            ans.push_back(c);
            dfs(ans, pos + 1);
            ans.erase(ans.end() - 1);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        numMap.emplace('2', "abc");
        numMap.emplace('3', "def");
        numMap.emplace('4', "ghi");
        numMap.emplace('5', "jkl");
        numMap.emplace('6', "mno");
        numMap.emplace('7', "pqrs");
        numMap.emplace('8', "tuv");
        numMap.emplace('9', "wxyz");
        input = digits;
        dfs("", 0);
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.letterCombinations("23").size();
}