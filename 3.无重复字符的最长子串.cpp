/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int max_len = 0, fast = 0, slow = 0;
        for (; fast < s.size(); ++fast)
        {
            if (char_set.find(s[fast]) == char_set.end())
            {
                char_set.insert(s[fast]);
                continue;
            }
            max_len = max(max_len, fast - slow);
            while (slow < fast)
            {
                char old = s[slow++];
                if (old == s[fast]) break;
                char_set.erase(old);
            }
        }
        max_len = max(max_len, fast - slow);
        return max_len;
    }
};

// int main(void)
// {
//     string str = "abcabcbb";
//     Solution s;
//     s.lengthOfLongestSubstring(str);
// }
// @lc code=end

