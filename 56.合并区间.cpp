/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> &first = merged[merged.size()-1];
            vector<int> &second = intervals[i];
            if (first[1] >= second[0])
            {
                if (second[1] > first[1]) first[1] = second[1];
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

// int main(void)
// {
//     Solution s;
//     vector<vector<int>> intervals;
//     s.merge(intervals);
// }

// @lc code=end

