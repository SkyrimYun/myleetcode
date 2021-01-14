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
        //倒序操作
        //如果nums1>nums2，在nums1内部改变元素顺序
        //如果nums1<=nums2，把nums2元素插入nums1
        int i = m + n - 1;
        m--;
        n--;
        while (n >= 0) //因为是 num2插入num1，所以只要num2里还有元素就要往里面插
        {
            while (m >= 0 && nums1[m] > nums2[n]) //m>=0是为了那种m已经空了但n还有元素要往里面放的情况
                swap(nums1[i--], nums1[m--]);     //把0放到该放的地方去
            swap(nums1[i--], nums2[n--]);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
}