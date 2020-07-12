/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<int> st;
//     vector<vector<int>> res;

//     void DFS(vector<int>& nums, int start)
//     {
//         if (start >= nums.size())
//         {
//             res.push_back(st);
//             return;
//         }
            
//         DFS(nums, start + 1);
//         st.push_back(nums[start]);
//         DFS(nums, start + 1);
//         st.pop_back();
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         DFS(nums, 0);

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res;
//         uint64_t mask = pow(2, nums.size());
//         for (uint64_t i = 0; i < mask; ++i)
//         {
//             uint64_t mask_num = i;
//             vector<int> set;
//             for (int j = 0; mask_num != 0; ++j)
//             {
//                 if (mask_num % 2 == 1) set.push_back(nums[j]);
//                 mask_num /= 2;
//             }
//             res.push_back(set);
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector<int> track;
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int start)
    {
        res.push_back(track);
        for (int i = start; i < nums.size(); ++i)
        {
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

// int main(void)
// {
//     vector<int> nums = {1, 2, 3};
//     Solution s;
//     s.subsets(nums);
// }

// @lc code=end

