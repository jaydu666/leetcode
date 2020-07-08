/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[start] == target) return start;
            if (nums[end] == target) return end;
            if (nums[mid] == target) return mid;
            if (nums[start] < nums[mid])
            {
                if (nums[start] < target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target < nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

// int main(void)
// {
//     vector<int> v = {4,5,6,7,0,1,2};
//     Solution s;
//     s.search(v, 0);
// }

// @lc code=end

