/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size(); ++first)
        {
            if (first > 0 && nums[first-1] == nums[first])
                continue;
            int target = -nums[first];
            int second = first + 1;
            int three = nums.size() - 1;
            while (second < three)
            {
                if (second - first > 1 && nums[second] == nums[second - 1])
                {
                    second += 1;
                    continue;
                }
                    
                if ((nums.size()-1) - three > 0 && nums[three] == nums[three + 1])
                {
                    three -= 1;
                    continue;
                }
                int sum = nums[second] + nums[three];
                if (sum < target)
                    second += 1;
                else if (sum > target)
                    three -= 1;
                else
                    res.push_back(vector<int>({nums[first], nums[second++], nums[three--]}));
            }
        }
        return res;
    }
};

// int main(void)
// {
//     vector<int> input = {-2,0,1,1,2};
//     Solution::threeSum(input);
// }

// @lc code=end

