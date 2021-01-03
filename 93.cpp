/*
稍微优雅一些的string转int：
int sub_num = 0;
for (int j = 0; j < sub.size(); j++)
    sub_num = sub_num * 10 + (sub[j] - '0');

或者调用函数
stoi() string -> int
stod() string -> double
to_string()   int/double -> string
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Solution
{
private:
    vector<string> ret;
    void dfs(string &candidate, int pos, int level, string &s)
    {
        if (pos == s.size() && level == 4)
        {
            ret.emplace_back(candidate);
            return;
        }

        if (level == 4 || pos == s.size())
            return;

        for (int i = 1; pos + i <= s.size() && i < 4; i++)
        {
            string sub = s.substr(pos, i);
            int sub_num = 0;
            for (int j = 0; j < sub.size(); j++)
                sub_num = sub_num * 10 + (sub[j] - '0');
            if ((i > 1 && sub[0] == '0') || sub_num > 255)
                continue;

            candidate += sub;
            candidate += level == 3 ? "" : ".";
            dfs(candidate, pos + i, level + 1, s);
            candidate.resize(candidate.size() - i - level == 3 ? 0 : 1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4)
            return ret;
        string temp;
        dfs(temp, 0, 0, s);
        return ret;
    }
};

int main()
{
    Solution s;
    string ss = "1111";
    vector<string> ret = s.restoreIpAddresses(ss);
    for (string ans : ret)
        cout << ans << endl;
}