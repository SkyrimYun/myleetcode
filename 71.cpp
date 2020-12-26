/*
c++里碰到按照给定字符分离字符串的问题
直接stringstream + getline(ss,s,'/')来处理
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> names;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/'))
        {
            if (!token.empty() && token != ".")
            {
                if (token == "..")
                {
                    if (!names.empty())
                        names.erase(names.end() - 1);
                }
                else
                    names.emplace_back(token);
            }
        }
        string ret;
        for (string s : names)
        {
            ret += "/" + s;
        }
        if (ret.empty())
            ret += "/";

        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/a/../../b/../c//.//");
}