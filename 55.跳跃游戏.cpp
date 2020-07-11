/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return true;
        int len = 0;
        for (int i = 0; i <= len && len <= nums.size()-1; ++i)
        {
            len = max(len, i + nums[i]);
        }
        return len >= nums.size()-1;
    }
};

// int main(void)
// {
//     Solution s;
//     vector<int> nums = {3,2,1,0,4};
//     s.canJump(nums)
// }

// @lc code=end

