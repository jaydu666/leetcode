/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> st;
    vector<vector<int>> res;
    set<int> set_int;
    void DFS(vector<int>& nums)
    {
        if (st.size() == nums.size())
        {
            res.push_back(st);
            return;
        }
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (set_int.find(*it) != set_int.end())
                continue;
            set_int.insert(*it);
            st.push_back(*it);
            DFS(nums);
            set_int.erase(*it);
            st.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        DFS(nums);
        return res;
    }
};

// int main(void)
// {
//     Solution s;
//     vector<int> nums = {1,2,3};
//     s.permute(nums);
// }

// @lc code=end

