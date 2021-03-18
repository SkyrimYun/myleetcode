#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> lookuptable;
        for (int n : nums)
            lookuptable.insert(n);

        int maxcount = 0;
        for (int n : nums)
        {
            if (lookuptable.count(n - 1) > 0)
                continue;

            int count_p = n + 1;
            while (lookuptable.count(count_p) > 0)
                count_p++;

            maxcount = max(maxcount, count_p - n);
        }
        return maxcount;
    }
};

int main()
{
    Solution s;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
}