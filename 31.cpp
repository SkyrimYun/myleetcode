#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        vector<int>::iterator pos = nums.end() - 1;
        while (pos != nums.begin() && *pos <= *(pos - 1))
            pos--;
        if (pos == nums.begin())
        {
            sort(nums.begin(), nums.end());
            return;
        }

        sort(pos, nums.end());
        vector<int>::iterator pos1 = pos;
        while (*pos1 <= *(pos - 1))
            pos1++;
        swap(*(pos - 1), *pos1);
    }
};

int main()
{
    vector<int> nums{2, 3, 1};
    Solution s;
    s.nextPermutation(nums);
    for (int n : nums)
        cout << n;
}