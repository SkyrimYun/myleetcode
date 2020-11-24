#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        int count = 1;
        while (count < n)
        {
            string ite;
            int repeat = 1;
            for (int i = 0; i < ret.size(); i++)
            {
                if (i < ret.size() - 1 && ret[i] == ret[i + 1])
                {
                    repeat++;
                    continue;
                }
                else
                {
                    ite += (repeat + '0');
                    ite += ret[i];
                    repeat = 1;
                }
            }
            ret = ite;
            count++;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(6);
}