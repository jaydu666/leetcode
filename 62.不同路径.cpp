/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(int i, int j, int m, int n)
    {
        if (0 <= i && i < n && 0 <= j && j < m)
            return true;
        else
            return false;
    }

    int uniquePaths(int m, int n) {
        int v[100][100];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                {
                    v[i][j] = 1;
                    continue;
                }
                    
                int left = is_valid(i-1, j, m, n)? v[i-1][j]: 0;
                int top = is_valid(i, j-1, m, n)? v[i][j-1]: 0;
                v[i][j] = left + top;
            }
        }
        return v[n-1][m-1];
    }
};

// int main(void)
// {
//     Solution s;
//     s.uniquePaths(3, 2);
// }

// @lc code=end

