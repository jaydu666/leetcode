/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void DFS(vector<int>& nums, int start)
    {
        if (start + 1 > nums.size())
        {
            res.push_back(nums);
            return;
        }

        unordered_set<int> set_int;
        for (int i = start; i < nums.size(); ++i)
        {
            if (set_int.find(nums[i]) != set_int.end())
                continue;
            set_int.insert(nums[i]);
            swap(nums[i], nums[start]);
            DFS(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        DFS(nums, 0);
        return res;
    }
};
// @lc code=end

