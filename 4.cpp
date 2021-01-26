/*
此题联动 88 -> 合并两个有序数组

如果复杂度要求 log(m+n), 第一时间想到二分

将此题转换为求 两个有序数组中第k小的元素
两个数组个数和为奇数 -> 求第(m+n)/2+1小的元素
两个数组个数和为偶数 -> 求第(m+n)/2小和第(m+n)/2+1小的元素，求其平均数

需要切割两个数组，在第一个数组i处切割，第二个数组j处切割
要求：
    i+j=k
    a[i-1]<=b[j] && b[j-1]<=a[i] 就是切割完之后左边的元素都需要小于右边元素

在哪里切？
    二分查找


技巧：输入两个数组需要比较数组长度以便处理的时候
    确定长度之后再用好的参数顺序调用自己递归一次就行

*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

class Solution
{
private:
    int findKth(vector<int> &num1, vector<int> &num2, int k)
    {
        assert(1 <= k && k <= num1.size() + num2.size());
        // 切割点须同时满足 0<=i<=m-1 && 0<=j<=n-1 && i+j=k-1
        // 所以 max(0,k-n)<=i<=min(k-1,m-1)
        int left = max(0, int(k - num2.size()));
        int right = min(k - 1, int(num1.size() - 1));
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // mid: num1切完左边的数
            // k-1-mid: num2切完右边的数
            // 这里比较两者大小
            // 另一个判断条件在else里面被隐式表达了
            if (num2[k - 1 - mid] > num1[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        //处理边界情况
        //二分的结果left值为顺序，所以需要减1得到index
        int nums1LeftMax = left == 0 ? INT32_MIN : num1[left - 1];
        int nums2LeftMax = left == k ? INT32_MIN : num2[k - left - 1];
        return max(nums1LeftMax, nums2LeftMax);
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size() + nums2.size();
        if (n & 1)                                      //奇数情况 二进制或运算 末位0&1=0，奇数；1&1=1，偶数
            return findKth(nums1, nums2, (n >> 1) + 1); //就等于 n/2+1; 太骚了
        else
            return (findKth(nums1, nums2, n >> 1) + findKth(nums1, nums2, (n >> 1) + 1)) / 2.0;
    }
};