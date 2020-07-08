/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int div(int dividend, int divisor)
    {
        if (dividend > divisor)
            return 0;
        int count = 1;
        int sum = divisor;
        while ((INT_MIN - sum) < sum && (sum + sum) > dividend)
        {
            count += count;
            sum += sum;
        }
        return count + div(dividend-sum, divisor);
    }

    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return 0;
        else if (divisor == -1 && dividend == INT_MIN)
            return INT_MAX;
        else if (divisor == 1 || divisor == -1)
            return dividend * divisor;
        int sign = (dividend < 0? -1: 1) * (divisor < 0? -1: 1);
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        return sign * div(dividend, divisor);
    }
};

// int main(void)
// {
//     Solution s;
//     s.divide(2147483647, 2);
// }
// @lc code=end

