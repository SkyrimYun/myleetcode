/*
数字转罗马数字

    那几个所谓的特殊情况其实并没有任何特殊之处
    就用常规方法，纳进去一起处理就可以了
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        const vector<int> vals{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const vector<string> roman{"M", "CM", "D", "CD",
                                   "C", "XC", "L", "XL",
                                   "X", "IX", "V", "IV", "I"};
        string ret;

        for (int i = 0; i < 13; i++)
        {
            while (num / vals[i] != 0)
            {
                ret += roman[i];
                num -= vals[i];
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(1994);
}