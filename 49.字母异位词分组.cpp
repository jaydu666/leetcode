/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> str_map;
        for (auto it = strs.begin(); it != strs.end(); ++it)
        {
            string str = *it;
            sort(str.begin(), str.end());
            int index = 0;
            if (str_map.find(str) == str_map.end())
            {
                str_map[str] = index = res.size();
                res.push_back(vector<string>());
            }
            index = str_map[str];
            res[index].push_back(*it);
        }
        return res;
    }
};
*/

#define LETTER_SIZE 26

struct Count {
    int letter_count[LETTER_SIZE];
    Count(const string &str)
    {
        memset(letter_count, 0, sizeof(letter_count));
        for (int i = 0; i < str.size(); ++i)
            letter_count[str[i]-'a'] += 1;
    }
};

struct CountHash
{
    size_t operator ()(const Count &p) const
    {
        size_t res = 0;
        for (int i = 1; i <= LETTER_SIZE; ++i)
            res += i * p.letter_count[i-1];
        return hash<int>()(res);
    }
};

struct CountEqual
{
    bool operator ()(const Count &c1, const Count &c2) const
    {
        return 0 == memcmp(c1.letter_count, c2.letter_count, sizeof(int) *LETTER_SIZE);
    }
};


class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<Count, int, CountHash, CountEqual> count_map;
        for (auto str_it = strs.begin(); str_it != strs.end(); ++str_it)
        {
            Count count(*str_it);
            int index = 0;
            auto it = count_map.find(count);
            if (it == count_map.end())
            {
                count_map[count] = index = res.size();
                res.push_back(vector<string>());
            }
            else
                index = it->second;
            res[index].push_back(*str_it);
        }
        return res;
    }
};

// int main(void)
// {
//     vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
//     Solution s;
//     s.groupAnagrams(strs);
// }

// @lc code=end

