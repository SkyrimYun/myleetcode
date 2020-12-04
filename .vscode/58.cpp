#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;
        string revs;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            revs.push_back(s[i]);
        }
        int sz = 0;
        for (char c : revs)
        {
            if (c == ' ')
            {
                if (sz == 0)
                    continue;
                else
                    return sz;
            }
            sz++;
        }
        return sz;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord(" a  bb ");
}