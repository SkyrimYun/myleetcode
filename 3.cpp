/*
hashtable.insert({key,value});
hashtable.emplace(key,value);
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> table;
        int pos1 = 0, pos2 = 0;
        int ret = 0;
        while (pos2 < s.size())
        {
            unordered_map<char, int>::iterator it = table.find(s[pos2]);
            if (it != table.end() && it->second >= pos1)
                pos1 = it->second + 1;

            table[s[pos2]] = pos2;
            ret = max(ret, pos2 - pos1 + 1);
            pos2++;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");
}