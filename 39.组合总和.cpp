/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> st;
    void DFS(vector<vector<int>> &res, vector<int>& candidates, int start, int target)
    {
        if (0 == target)
            res.push_back(st);
        else if (target < 0)
            return;
        for (int i = start; i < candidates.size(); ++i)
        {
            st.push_back(candidates[i]);
            DFS(res, candidates, i, target - candidates[i]);
            st.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        DFS(res, candidates, 0, target);
        return res;
    }
};
// @lc code=end

