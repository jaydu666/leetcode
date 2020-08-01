/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    vector<int> st;
    // vector<int> nums;

    void backtrack(const vector<int>& nums, int start)
    {
        res.push_back(st);
        for (int i = start; i < nums.size(); ++i)
        {
            if (i > start && nums[i] == nums[i-1])
                continue;
            st.push_back(nums[i]);
            backtrack(nums, i + 1);
            st.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // this->nums = nums;
        backtrack(nums, 0);
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> cur;
//     vector<int> v;
//     void dfs(int idx) {
//         ans.push_back(cur);
//         if(idx == v.size()) {
//             return;
//         }
//         for(int i=idx; i<v.size(); ++i) {
//             if(i > idx && v[i] == v[i-1]) continue;
//             cur.push_back(v[i]);
//             dfs(i+1);
//             cur.pop_back();
//         }
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         v = nums;
//         dfs(0);
//         return ans;
//     }
// };

// @lc code=end

