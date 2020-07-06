/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size() + 1) / 2;
        bool more = ((nums1.size() + nums2.size()) % 2) == 0;
        int i = 0, j = 0, k = 0;
        for (; k < (mid - 1); ++k)
        {
            if (i >= nums1.size())
            {
                ++j;
            }
            else if (j >= nums2.size())
            {
                ++i;
            }
            else
            {
                if (nums1[i] < nums2[j])
                    ++i;
                else
                    ++j;
            }
        }
        int left = 0, right = 0;
        if ( i >= nums1.size() )
        {
            left = nums2[j++];
        }
        else if (j >= nums2.size())
        {
            left = nums1[i++];
        }
        else
        {
            if (nums1[i] < nums2[j])
                left = nums1[i++];
            else
                left = nums2[j++];
        }
        if (!more)
            return left;
        if ( i >= nums1.size() )
        {
            right = nums2[j++];
        }
        else if (j >= nums2.size())
        {
            right = nums1[i++];
        }
        else
        {
            if (nums1[i] < nums2[j])
                right = nums1[i++];
            else
                right = nums2[j++];
        }
        return (left + right) / 2.0;
    }
};

// int main(void)
// {
//     vector<int> nums1 = {2};
//     vector<int> nums2 = {};
//     std::cout << Solution::findMedianSortedArrays(nums1, nums2) << std::endl;
// }
// @lc code=end

