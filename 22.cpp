#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<string> ret;
    int sz;
    int left;
    int right;
    void dfs(string cur, int pos)
    {
        if (pos == sz)
        {
            ret.emplace_back(cur);
            return;
        }
        if (left == right)
        {
            cur.push_back('(');
            left++;
            dfs(cur, pos + 1);
            left--;
            cur.erase(cur.end() - 1);
        }
        else if (left > right && left < sz / 2)
        {
            cur.push_back('(');
            left++;
            dfs(cur, pos + 1);
            left--;
            cur.erase(cur.end() - 1);
            cur.push_back(')');
            right++;
            dfs(cur, pos + 1);
            right--;
            cur.erase(cur.end() - 1);
        }
        else
        {
            cur.push_back(')');
            right++;
            dfs(cur, pos + 1);
            right--;
            cur.erase(cur.end() - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        sz = n * 2;
        left = right = 0;
        dfs("", 0);
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> ret = s.generateParenthesis(3);
    for (string s : ret)
        cout << s << endl;
}