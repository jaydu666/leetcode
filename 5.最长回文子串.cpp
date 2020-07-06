/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

class Solution {
public:
    static string longestPalindrome(string s) {
        int max = -1;
        int start = -1, end = -1;
        for (int j = 0; j < s.size(); ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                if (j - i == 0)
                {
                    dp[i][j] = 1;
                }
                else if (j - i == 1)
                {
                    dp[i][j] = (s[i] == s[j])? 2: -1;
                }
                else if (j - i == 2)
                {
                    dp[i][j] = (s[i] == s[j])? 3: -1;
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] != -1)? (dp[i+1][j-1]+2): -1;
                }
                if (dp[i][j] > max)
                {
                    max = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        if (start == -1 || end == -1)
            return "";
        return s.substr(start, end - start + 1);
    }
};

// int main(void)
// {
//     std::cout << Solution::longestPalindrome("aaaa") << std::endl;

//     return 0;
// }
// @lc code=end

