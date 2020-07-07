/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        stringstream ss;
        int z_len = (numRows - 1) * 2;
        for (int i = 0; i < numRows; ++i)
        {
            int left = z_len - i * 2;
            int right = i * 2;
            bool add_left = true;
            for (int j = i; j < s.size(); )
            {
                ss << s[j];
                int step = 0;
                while (step == 0)
                {
                    step = add_left? left: right;
                    add_left = !add_left;
                }
                j += step;
            }
        }
        return ss.str();
    }
};
// @lc code=end

