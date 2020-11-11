#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty() || haystack == needle)
            return 0;
        if (haystack.empty() || needle.size() > haystack.size())
            return -1;

        int sz1 = haystack.size();
        int sz2 = needle.size();

        int end = 0;
        for (int start = 0; start <= sz1 - sz2; start++)
        {
            for (end = start; end < start + sz2; end++)
            {
                if (haystack[end] != needle[end - start])
                    break;
            }
            if (end == start + sz2)
                return start;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("abc", "c");
}