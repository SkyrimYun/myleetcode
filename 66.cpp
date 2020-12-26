#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int sz = digits.size();
        bool plusone = true;
        for (int i = sz - 1; i >= 0; i--)
        {
            if (!plusone)
                break;
            digits[i] += 1;
            if (digits[i] >= 10)
            {
                plusone = true;
                digits[i] %= 10;
            }
            else
                plusone = false;
        }
        if (plusone)
            digits.insert(digits.begin(), 1);
    }
};