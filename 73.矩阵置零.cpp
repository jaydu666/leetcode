/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// #define VAL 235641

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         for (int i = 0; i < matrix.size(); ++i)
//         {
//             for (int j = 0; j < matrix[i].size(); ++j)
//             {
//                 if (matrix[i][j] != 0)
//                     continue;
//                 // 行置为VAL
//                 for (int k = 0; k < matrix[i].size(); ++k)
//                 {
//                     if (matrix[i][k] != 0)
//                         matrix[i][k] = VAL;
//                 }
//                 // 列置为VAL
//                 for (int k = 0; k < matrix.size(); ++k)
//                 {
//                     if (matrix[k][j] != 0)
//                         matrix[k][j] = VAL;
//                 }
//             }
//         }
//         for (int i = 0; i < matrix.size(); ++i)
//         {
//             for (int j = 0; j < matrix[i].size(); ++j)
//             {
//                 if (matrix[i][j] == VAL)
//                     matrix[i][j] = 0;
//             }
//         }
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col_zero = false;
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
                col_zero = true;
            for (int j = 1; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i)
        {
            if (matrix[0][i] != 0)
                continue;
            for (int j = 1; j < matrix.size(); ++j)
                matrix[j][i] = 0;
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] != 0)
                continue;
            for (int j = 1; j < matrix[i].size(); ++j)
                matrix[i][j] = 0;
        }
        if (col_zero)
            for (int j = 0; j < matrix.size(); ++j)
                matrix[j][0] = 0;
    }
};

// int main()
// {
//     vector<vector<int>> matrix = {{1}, {0}};
//     Solution s;
//     s.setZeroes(matrix);
// }

// @lc code=end

