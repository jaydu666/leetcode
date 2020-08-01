/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool valid(char first, char second)
    {
        if (first == '0') return false;
        int num = (first-'0')*10 + (second-'0');
        return 1 <= num && num <= 26;
    }

    bool valid(char first)
    {
        return '0' < first && first <= '9';
    }

    int numDecodings(string s) {
        int first = 0, second = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int nums1 = valid(s[i])? ((i-1)>=0? second: 1): 0;
            int nums2 = ((i-1)>=0 && valid(s[i-1], s[i]))? (i-2>=0? first: 1): 0;
            first = second;
            second = nums1 + nums2;
        }
        return second;
    }
};

// int main(void)
// {
//     Solution s;
//     s.numDecodings("12");
// }
// @lc code=end

