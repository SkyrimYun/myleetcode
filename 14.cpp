#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret;
        if (strs.empty())
            return ret;
        string s = strs[0];
        for (int pos = 0; pos < s.size(); pos++)
        {
            for (string ss : strs)
            {
                if (s[pos] != ss[pos])
                    return ret;
            }
            ret.push_back(s[pos]);
        }
        return ret;
    }
};