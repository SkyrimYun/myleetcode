/*
双指针，滑动窗口
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
private:
    unordered_map<char, int> ts;
    bool validcheck()
    {
        for (pair<char, int> p : ts)
        {
            if (p.second <= 0)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        for (char c : t)
            ts[c] = ts.count(c) != 0 ? ts[c] - 1 : 0;

        int pt1;
        for (pt1 = 0; pt1 < s.size(); pt1++)
        {
            if (ts.count(s[pt1]) != 0)
            {
                ts[s[pt1]]++;
                if (validcheck())
                    return t;
                break;
            }
        }
        int pt2 = pt1 + 1;
        int minlength = s.size();
        int minf;

        vector<int> jumpto;
        int jumpindex = 0;

        while (pt2 < s.size() && pt1 < s.size())
        {
            if (ts.count(s[pt2]) != 0)
            {
                ts[s[pt2]]++;
                jumpto.push_back(pt2);

                if (validcheck())
                {
                    while (ts[s[pt1]] > 1)
                    {
                        ts[s[pt1]]--;
                        pt1 = jumpto[jumpindex];
                        jumpindex++;
                    }

                    if (pt2 - pt1 < minlength)
                    {
                        minlength = pt2 - pt1;
                        if (minlength == t.size() - 1)
                            return s.substr(pt1, minlength + 1);
                        minf = pt1;
                    }

                    ts[s[pt1]]--;
                    pt1 = jumpto[jumpindex];
                    jumpindex++;
                }
            }
            pt2++;
        }

        return minlength == s.size() ? "" : s.substr(minf, minlength + 1);
    }
};

int main()
{
    string s = "ABC";
    string t = "AC";
    Solution sol;
    string ss = sol.minWindow(s, t);
    cout << ss;
}