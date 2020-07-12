/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int loc1 = -1, loc2 = -1;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             int loc = i, num = nums[i];
//             if (loc2 != -1 && num < nums[loc2])
//             {
//                 nums[loc] = nums[loc2++];
//                 loc = loc2 -1;
//             }

//             if (loc1 != -1 && num < nums[loc1])
//             {
//                 nums[loc] = nums[loc1++];
//                 loc = loc1 - 1;
//             }
//             nums[loc] = num;

//             if (nums[loc] == 2 && loc2 == -1)
//                 loc2 = loc;
//             else if (nums[loc] == 1 && loc1 == -1)
//                 loc1 = loc;
//         }
//     }
// };

class Solution {
public:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size()-1;
        for (int i = 0; i <= p2;)
        {
            if (nums[i] == 0) swap(nums[p0++], nums[i++]);
            else if (nums[i] == 2) swap(nums[p2--], nums[i]);
            else ++i;
            
        }
    }
};

// int main(void)
// {
//     Solution s;
//     vector<int> nums = {2,0,1};
//     s.sortColors(nums);
// }
// @lc code=end

