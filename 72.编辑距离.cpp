/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


int dp[1000][1000];

class Solution {
public:
    int get(int i, int j)
    {
        if (i < 0 && j < 0)
            return 0;
        if (i < 0)
            return j + 1;
        else if (j < 0)
            return i + 1;
        return dp[i][j];
    }

    int min(int i, int j, int k)
    {
        i = i > j? j: i;
        return i > k? k: i;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n * m == 0) return n + m;

        for (int i = 0; i < word1.size(); ++i)
        {
            for (int j = 0; j < word2.size(); ++j)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = get(i-1, j-1);
                    continue;
                }
                dp[i][j] = min(get(i-1, j-1), get(i, j-1), get(i-1, j)) + 1;
            }
        }
        return dp[word1.size()-1][word2.size()-1];
    }
};
// @lc code=end

