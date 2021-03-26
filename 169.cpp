/*
分治，迭代法
核心思想：把数组对半分，数组的众数也必然是其中一个子数组的众数
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

class Solution
{
public:
    // int majorityElement(vector<int> &nums)
    // {
    //     // sort(nums.begin(), nums.end());
    //     // return nums[nums.size() / 2];
    // }

    int count_in_range(vector<int> &nums, int target, int lo, int hi)
    {
        int count = 0;
        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target)
                ++count;
        return count;
    }
    int majority_element_rec(vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;
        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)
            return right_majority;
        return -1;
    }

public:
    int majorityElement(vector<int> &nums)
    {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
};