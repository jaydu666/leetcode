/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

/*
 * (0, y) -> (y, side_len-1) -> (side_len-1, side_len-1-y) -> (side_len-1-y, 0) -> (0, y)
 * 0 <= y < side_len-1
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1)/2; ++i)
        {
            int side_len = n - i * 2; // 边长
            for (int j = 0; j < side_len-1; ++j)
            {
                int tmp = matrix[i+0][i+j];
                matrix[i+0][i+j] = matrix[i+side_len-1-j][i+0];
                matrix[i+side_len-1-j][i+0] = matrix[i+side_len-1][i+side_len-1-j];
                matrix[i+side_len-1][i+side_len-1-j] = matrix[i+j][i+side_len-1];
                matrix[i+j][i+side_len-1] = tmp;
            }
        }
    }
};

// int main(void)
// {
//     vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
//     Solution s;
//     s.rotate(matrix);
// }
// @lc code=end

