/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int first = nums.size() - 1;
        for (; first > 0; --first)
        {
            if (nums[first - 1] < nums[first])
                break;
        }
        if (first > 0)
        {
            int second = nums.size() - 1;
            for (; second >= first; --second)
            {
                if (nums[second] > nums[first - 1])
                {
                    swap(nums[second], nums[first - 1]);
                    break;
                }
            }
        }

        int i = first, j = nums.size() - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            ++i, --j;
        }
    }
};
// @lc code=end

