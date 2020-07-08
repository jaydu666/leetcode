/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

#define MAX 1024

class Solution {
public:
    char char_set[MAX];
    void traverse(vector<string> &res, int left_num, int right_num, int n)
    {
        if (left_num > n || right_num > n)  return;
        if (left_num == n && right_num == n) res.push_back(string(char_set, n*2));
        if (right_num > left_num) return;
        char_set[left_num + right_num] = '(';
        traverse(res, left_num + 1, right_num, n);
        char_set[left_num + right_num] = ')';
        traverse(res, left_num, right_num + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        traverse(res, 0, 0, n);

        return res;
    }
};

// int main(void)
// {
//     Solution s;
//     s.generateParenthesis(3);
// }
// @lc code=end

