/*
这玩意用迭代器不好弄
别轻易动删插vector的念头
到最后再来截取比较合适
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int j = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[++j] = nums[i + 1];
            }
        }
        return j + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 1, 2, 2, 3, 4, 5};
    cout << s.removeDuplicates(nums);
}