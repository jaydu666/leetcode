/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<int32_t, vector<char>> digit_map = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };

    char str[10];

    void traverse(vector<string> &res, string &digits, int i)
    {
        if (i >= digits.size())
        {
            if (digits.size() > 0) res.push_back(string(str, digits.size()));
            return;
        }
        int num = digits[i] - '0';
        vector<char> &char_set = digit_map[num];
        for (auto it = char_set.begin(); it != char_set.end(); ++it)
        {
            str[i] = *it;
            traverse(res, digits, i + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        traverse(res, digits, 0);
        return res;
    }
};
// @lc code=end

