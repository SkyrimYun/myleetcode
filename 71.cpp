/*
c++里碰到按照给定字符分离字符串的问题
直接stringstream + getline(ss,s,'/')来处理

这个题之所以不直接用stack容器的原因：其实数据需要先进先出而不是先进后出
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
        stringstream ss(path);
        string token;
        stack<string> tokens;
        while (getline(ss, token, '/'))
        {
            if (!token.empty())
            {
                if (token == ".")
                    continue;
                else if (token == ".." && !tokens.empty())
                    tokens.pop();
                else
                    tokens.push(token);
            }
        }
        string ret;
        while (!tokens.empty())
        {
            ret += ("/" + tokens.top());
            tokens.pop();
        }
        if (ret.empty())
            ret = "/";

        return ret;
    }
    // string simplifyPath(string path)
    // {
    //     vector<string> names;
    //     stringstream ss(path);
    //     string token;
    //     while (getline(ss, token, '/'))
    //     {
    //         if (!token.empty() && token != ".")
    //         {
    //             if (token == "..")
    //             {
    //                 if (!names.empty())
    //                     names.erase(names.end() - 1);
    //             }
    //             else
    //                 names.emplace_back(token);
    //         }
    //     }
    //     string ret;
    //     for (string s : names)
    //     {
    //         ret += "/" + s;
    //     }
    //     if (ret.empty())
    //         ret += "/";

    //     return ret;
    // }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/../");
    //"/a/../../b/../c//.//"
}