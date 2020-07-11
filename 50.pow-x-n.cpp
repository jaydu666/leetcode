/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double pow(double x, long long n)
    {
        if (n == 0)
            return 1;
        double res = pow(x, n / 2);
        return res * res * (((n%2)!=0)? x: 1);
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0)
            return 1.0 / pow(x, -N);
        else
            return pow(x, N);
    }
};

// @lc code=end

