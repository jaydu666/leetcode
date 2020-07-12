/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool DFS(vector<vector<char>>& board, int row, int col, std::string &search_word, int start)
    {
        if (board.size() == 0 || !(0 <= row && row < board.size()
            && 0 <= col && col < board[row].size()))
            return false;
        if (board[row][col] == 0) return false;
        if (board[row][col] != search_word[start])
            return false;
        if (start == search_word.size()-1)
            return true;

        char tmp = board[row][col]; board[row][col] = 0;
        bool res =  DFS(board, row-1, col, search_word, start + 1) ||
                    DFS(board, row, col-1, search_word, start + 1) ||
                    DFS(board, row, col+1, search_word, start + 1) ||
                    DFS(board, row+1, col, search_word, start + 1);
        board[row][col] = tmp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (DFS(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};

// int main()
// {
//     vector<vector<char>> board = {
//                                     {'A','B','C','E'},
//                                     {'S','F','C','S'},
//                                     {'A','D','E','E'}
//                                  };
//     Solution s;
//     bool res = s.exist(board, "ABCCED");
//     std::cout << res << std::endl;
// }

// @lc code=end

