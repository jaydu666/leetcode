/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = -1, fast = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[fast + 1] = nums[i];
            if (fast == -1 || nums[fast] != nums[fast + 1])
            {
                slow = fast = fast + 1;
            }
            else if (fast - slow < 1)
            {
                fast = fast + 1;
            }
        }
        return fast + 1;
    }
};
// @lc code=end

