/*
directly use the row number as control variable, not the string index
push -> check -> update
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> rows(numRows);
        int temp = 0;
        bool order = false;
        for (char c : s)
        {
            rows[temp].push_back(c);
            if (temp == 0 || temp == numRows - 1)
                order = !order;
            temp += order ? 1 : -1;
        }
        string ret;
        for (string ss : rows)
        {
            ret += ss;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3);
}