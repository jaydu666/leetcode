/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int div_ceil(int dividend, int divider)
    {
        return (dividend / divider) + ((dividend % divider) > 0? 1: 0);
    }

    void move(string &nums, int from, int to)
    {
        if (from == to) return;
        int tmp = nums[to];
        for (int i = to; i > from; --i)
            nums[i] = nums[i-1];
        nums[from] = tmp;
    }

    string getPermutation(int n, int k) {
        int all = 1;
        string nums;
        for (int i = 1; i <= n; ++i)
        {
            nums.push_back('0' + i);
            all *= i;
        }

            
        for (int i = 0; i < n; ++i)
        {
            all /= (n - i);
            int loc = div_ceil(k, all) - 1;
            move(nums, i, i + loc);
            k -= loc * all;
        }
        return nums;
    }
};

// int main(void)
// {
//     Solution s;
//     s.getPermutation(3, 5);
// }
// @lc code=end

