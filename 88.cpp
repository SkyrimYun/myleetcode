/*
数组操作
insert不方便的时候
就用swap
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m + n - 1;
        m--;
        n--;
        while (n >= 0)
        {
            while (m >= 0 && nums1[m] > nums2[n])
                swap(nums1[i--], nums1[m--]);
            swap(nums1[i--], nums2[n--]);
        }
    }
};