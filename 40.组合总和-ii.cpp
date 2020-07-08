/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> st;

    void DFS(vector<vector<int>> &res, vector<int>& candidates, int start, int target)
    {
        if (target == 0)
            res.push_back(st);
        else if (target < 0)
            return;
        for (int i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i - 1] == candidates[i])
                continue;
            st.push_back(candidates[i]);
            DFS(res, candidates, i + 1, target - candidates[i]);
            st.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        DFS(res, candidates, 0, target);
        return res;
    }
};
// @lc code=end

