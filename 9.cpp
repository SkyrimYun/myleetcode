#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long num = x;
        long res = 0;
        while (num != 0)
        {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        if (res == x)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(2147483647);
}